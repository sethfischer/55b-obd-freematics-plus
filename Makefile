.PHONY: lint
lint: lint-c lint-python lint-shell lint-yaml

.PHONY: lint-c lint-python lint-shell lint-yaml
lint-c lint-python lint-shell lint-yaml:
	./$@.sh
