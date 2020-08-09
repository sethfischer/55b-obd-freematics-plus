.PHONY: git-hooks
git-hooks: .git/hooks/pre-commit

.git/hooks/%: git-hooks/%.sh
	install --mode=700 $< $@

.PHONY: lint
lint: lint-c lint-python lint-shell lint-yaml

.PHONY: lint-c lint-python lint-shell lint-yaml
lint-c lint-python lint-shell lint-yaml:
	./$@.sh

.PHONY: upload-debug
upload-debug:
	pio run -t upload -e freematics_one_plus_debug
	pio device monitor

.PHONY: upload-prod
upload-prod:
	pio run -t upload -e freematics_one_plus
	pio device monitor
