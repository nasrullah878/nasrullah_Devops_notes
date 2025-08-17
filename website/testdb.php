<?php
$conn = new mysqli("localhost", "nasrullah", "QueerKhan@125", "nk");

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} else {
    echo "Connected successfully!";
}
?>
