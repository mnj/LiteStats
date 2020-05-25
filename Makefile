# Alternative GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug)
  LiteStats_config = debug
  LiteStatsSvc_config = debug

else ifeq ($(config),release)
  LiteStats_config = release
  LiteStatsSvc_config = release

else ifeq ($(config),dist)
  LiteStats_config = dist
  LiteStatsSvc_config = dist

else
  $(error "invalid configuration $(config)")
endif

PROJECTS := LiteStats LiteStatsSvc

.PHONY: all clean help $(PROJECTS) 

all: $(PROJECTS)

LiteStats:
ifneq (,$(LiteStats_config))
	@echo "==== Building LiteStats ($(LiteStats_config)) ===="
	@${MAKE} --no-print-directory -C LiteStats -f Makefile config=$(LiteStats_config)
endif

LiteStatsSvc: LiteStats
ifneq (,$(LiteStatsSvc_config))
	@echo "==== Building LiteStatsSvc ($(LiteStatsSvc_config)) ===="
	@${MAKE} --no-print-directory -C LiteStatsSvc -f Makefile config=$(LiteStatsSvc_config)
endif

clean:
	@${MAKE} --no-print-directory -C LiteStats -f Makefile clean
	@${MAKE} --no-print-directory -C LiteStatsSvc -f Makefile clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug"
	@echo "  release"
	@echo "  dist"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   LiteStats"
	@echo "   LiteStatsSvc"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"