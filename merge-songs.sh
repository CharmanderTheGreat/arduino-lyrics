#!/usr/bin/env bash
# Merge each standalone song repo into this hub repo as a subfolder under songs/,
# preserving full commit history via git subtree-style merge.
#
# USAGE:
#   1. cd into your local clone of arduino-lyrics (the hub repo)
#   2. Make sure your working tree is clean (git status)
#   3. Run: bash merge-songs.sh
#
# After it finishes, review with `git log --oneline --graph`, then:
#   git push origin main

set -euo pipefail

# folder_name:repo_url  — edit/add lines here if you rename folders or add songs
SONGS=(
  "aboutyou:https://github.com/CharmanderTheGreat/aboutyou-lyrics.git"
  "damned:https://github.com/CharmanderTheGreat/damned-lyrics.git"
  "sila:https://github.com/CharmanderTheGreat/sila-lyrics.git"
  "totoongtayo:https://github.com/CharmanderTheGreat/totoongtayo-lyrics.git"
  "waltzoffourfeet:https://github.com/CharmanderTheGreat/waltzoffourfeet-lyrics.git"
)

# Safety checks
if [ ! -d .git ]; then
  echo "ERROR: run this from inside the hub repo (arduino-lyrics) root — no .git found here."
  exit 1
fi

if [ -n "$(git status --porcelain)" ]; then
  echo "ERROR: working tree not clean. Commit or stash changes first."
  exit 1
fi

mkdir -p songs

for entry in "${SONGS[@]}"; do
  folder="${entry%%:*}"
  url="${entry#*:}"
  remote_name="tmp-${folder}"

  echo ""
  echo "=== Merging ${folder} (${url}) ==="

  git remote add "${remote_name}" "${url}"
  git fetch "${remote_name}"

  # detect default branch (main or master)
  default_branch=$(git remote show "${remote_name}" | sed -n '/HEAD branch/s/.*: //p')
  echo "Default branch: ${default_branch}"

  git merge -s ours --no-commit --allow-unrelated-histories "${remote_name}/${default_branch}"
  git read-tree --prefix="songs/${folder}/" -u "${remote_name}/${default_branch}"
  git commit -m "Merge ${folder}-lyrics into songs/${folder}, preserving history"

  git remote remove "${remote_name}"

  echo "=== Done: ${folder} ==="
done

echo ""
echo "All songs merged. Review with: git log --oneline --graph --all"
echo "Then push with: git push origin main"
