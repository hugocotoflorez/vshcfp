# vshcfp

Very Simple Hugo's Config File Parser

## About vshcfp

This is a C interface for parsing .HCF files.

### About .HCF files

This type of files are plain text files that follows the  Hugo's Config File format. It is not needed that the file which is going to be parsed have this extension, but it has to follow the format standard.

### About HCF format standard

HCF files are designed to allow myself to change settings dynamically without the need of recompile the main executable.

#### Fields

Configurations in the same file can be grouped under single cofigurations groups also named fields. A field is represented as a word following by a colon. Field's configurations are declared after (under) the field name and before (above) the next field name or end of file.

```hcf
field:
...

field2:
...
```

#### Single Configuration

Single configurations are stored as a key name following by their value.

```hcf
field:
key value
key2 value2
key3 value3
```

#### Values: type and format

Values are stored as a string. There are no way to store numbers or other types directly. Programming interface allow users to get the right type from the value.

```hcf
key some value as 1234
```

#### Spaces and newlines

Lines starting by a newline are ignored. Trailing spaces after values are ignored. A space between keys and values is needed, but there can be more than one. Blank lines between keys are ignored.

#### Comments

The digraph `//` introduce a single line comment. All text before the digraph is ignored.

```hcf
field: // this is a comment
...
```

### Programming interface

See vshcfp.h
