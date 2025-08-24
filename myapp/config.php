
<?php
$servername = "localhost";
$username   = "webuser";       // MySQL username
$password   = "webpass";
$dbname     = "school";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
?>
