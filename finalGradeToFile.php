<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8">
        <meta name="author" content="River Bumpas and Surya Malik">
        <title>Final Grade/ GPA Calculator</title>
        <meta name="description" content="This page is for calculating a students final grade in a course and overall GPA.">
        <link href="style.css" rel="stylesheet" type="text/css" media="screen" />
    </head>
    <body>
    	<header>
    		<h1>Final Grade and GPA Calculator</h1>
            
    	</header>

        <nav class="menu">
            <ul>
                <li><a href="grade.php">Final Grade Calculator</a></li>
                <li><a href="gpa.php">GPA Calculator</a></li>
            </ul>
        </nav>

        <main>
            <h2>
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

                    $output = shell_exec("python3 $python_script $file");

                    echo 'Your average(s) are: ' .$output;
                ?>
            </h2>
        </main>  
    </body>   
</html>

