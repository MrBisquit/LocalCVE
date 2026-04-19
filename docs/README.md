<a id="docs"></a>
# LocalCVE documentation

- [Database documentation](database.md)
- [Folder stucture](#folder-structure)

<a id="folder-structure"></a>
## Folder structure

```
root
|-- cve             Contains the CVE git repo
|-- ghsa            Contains the GHSA git repo
|-- data.db         Contains all the indexed data
\-- config.cfg      Contains configuration data
```

The `cve`, and `ghsa` folders *can* be cleaned up after they have been
indexed, and added to the database to save on storage space, however,
this does mean that next time you need to update your database, you will
need to clone it again, **and then reindex all of the data**.