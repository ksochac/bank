TEMPLATE = subdirs

SUBDIRS = app tests

test.depends = app

CONFIG+=ordered
