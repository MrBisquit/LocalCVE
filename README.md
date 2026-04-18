@mainpage LocalCVE

# LocalCVE
The CVE database, but local.

This contains libraries, tools, and other things designed to do the following:

- Convert the JSON files from [https://github.com/CVEProject/cvelistV5](https://github.com/CVEProject/cvelistV5)
  into an sqlite3 database
- Search through the database
- Update the database with new changes
  - If the time between the last update surpasses an hour, it may scan
    the whole directory instead to see if there have been any other changes,
    [find out why](#limitations)
- Monitor the database (so you know when one of your dependencies has a reported vulnerability within the hour)
- Link into other databases, such as the [GitHub advisotry database](https://github.com/github/advisory-database/)

> [!NOTE]
> Please note that git operations are handled by the `localcve` backend library, since it needs to see the difference
> between the files.

## Usage
There are a few different ways to use LocalCVE, but before you do that, you need to set up your database.

## Limitations
This relies on the `delta.json` file within the git repository so that it does not constantly scan
through all the files.

It may in future be able to check through the `deltaLog.json` file, however, for now, this will
just use the `delta.json` file, and if it has been longer than an hour since the last check, it will
look through all the files to check if their last modification date was after the database record for it.
