CONSTANTS_FILE = include/Constants.tmp.h

-include Settings.mf

all: build upload

build: constants
	sudo pio run -e ${ENV}

upload: constants 
	sudo pio run --target upload -e ${ENV}

constants:
	cat $(CONSTANTS_FILE) | envsubst > include/Constants.h

.PHONY: all build upload constants
