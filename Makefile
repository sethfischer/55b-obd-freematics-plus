.PHONY: git-hooks
git-hooks: .git/hooks/pre-commit

.git/hooks/%: git-hooks/%.sh
	install --mode=700 $< $@

.PHONY: lint
lint: lint-c lint-python lint-shell lint-yaml

.PHONY: lint-c lint-python lint-shell lint-yaml
lint-c lint-python lint-shell lint-yaml:
	./$@.sh
