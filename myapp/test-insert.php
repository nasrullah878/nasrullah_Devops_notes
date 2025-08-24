<?php
error_reporting(E_ALL);
ini_set('display_errors', 1);

include 'config.php';

$sql = "INSERT INTO students (name, email, address) VALUES ('Test User', 'test@example.com', 'Test Address')";

if ($conn->query($sql)) {
    echo "✅ Insert successful";
} else {
    echo "❌ Error: " . $conn->error;
}
?>
