<?php


$data = "finalGrade" . "\n";

$file = 'results.txt';


foreach ($_POST['courses'] as $course) {
    $data .= $course['name'] . "\n";


    foreach ($course['categories'] as $category) {
        $data .=  $category['name'] . "," . $category['weight'] . ",";


        $numAssignments = count($category['assignments']);

        foreach ($category['assignments'] as $assignmentIndex => $assignment) {
            $data .= $assignment['name'] . "," . $assignment['score'];

            if($assignmentIndex < $numAssignments){
                $data .= ",";
            }
        }
        $data .= "\n";
    }
    $data .= "\n";
}


file_put_contents($file, '');

file_put_contents($file, $data, FILE_APPEND);

$python_script = 'process.py';

exec("python3 $python_script $file");
?>

