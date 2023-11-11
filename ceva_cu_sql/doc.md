<html>
<body>

<h1>Database Connector</h1>
<p>First you should create an env with<br><b>conda create --name sqlenv python=3.8</b><p>
<p>A database driver is a piece of software that allows an application to connect and interact with a database system.
Programming languages like Python need a special driver before they can speak to a database from a specific vendor.
<br><br>
These drivers are typically obtained as third-party modules. The Python Database API (DB-API) defines the standard interface with which all Python database drivers must comply. These details are documented in PEP 249. All Python database drivers, such as sqlite3 for SQLite, psycopg for PostgreSQL, and MySQL Connector/Python for MySQL, follow these implementation rules.
</p><br>
<p>Note: MySQL’s official documentation uses the term connector instead of driver. Technically, connectors are associated only with connecting to a database, not interacting with it. However, the term is often used for the entire database access module comprising the connector and the driver.
</p>
To maintain consistency with the documentation, you’ll see the term connector whenever MySQL is mentioned.
<h2>How to install conector</h2>
<b>conda install -c anaconda mysql-connector-python</r>
</b>
<br><br>
<p>Establishing a Connection With MySQL Server

MySQL is a server-based database management system. One server might contain multiple databases. To interact with a database, you must first establish a connection with the server. The general workflow of a Python program that interacts with a MySQL-based database is as follows:
<ol>
    Connect to the MySQL server.<br>
    Create a new database.<br>
    Connect to the newly created or an existing database.<br>
    Execute a SQL query and fetch results.<br>
    Inform the database if any changes are made to a table.<br>
    Close the connection to the MySQL server.<br>
</ol>
This is a generic workflow that might vary depending on the individual application. But whatever the application might be, the first step is to connect your database with your application.</p>
</body>
</html>