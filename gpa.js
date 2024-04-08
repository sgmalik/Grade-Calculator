document.addEventListener('DOMContentLoaded', function() { // waits until html loaded
    document.getElementById('addGrade').addEventListener('click', addGrade); // listens for click on addCourse button and calls addCourse function when it's triggered
    document.getElementById('gpaCalculator').addEventListener('submit', function(event) {
        if (document.getElementById('totalGrades').children.length < 1) {
            event.preventDefault(); // stops form submission and ensures at least one grade is given
            alert('At least one grade must be submitted.')
        }
    });
}); 

function addGrade() {
    const totalGrades= document.getElementById('totalGrades'); // gets element with totalGrades id attribute
    const additionalGrades = totalGrades.children.length + 1; // adds one to number of child elements of totalGrades
    const gradeDiv = document.createElement('div'); // creates html element
    gradeDiv.id = `grade${additionalGrades}`;
    gradeDiv.innerHTML = `
        <fieldset>
            <legend>Grade ${additionalGrades}</legend>
            <input type="text" name="course${additionalGrades}[0]" placeholder="Course Name" required>
            <input type="number" name="course${additionalGrades}[1]" placeholder="# of Credits" required min="1" max="19" step="1">
            <input type="text" name="course${additionalGrades}[2]" placeholder="Grade" required>
            <button type="button" class="remove" onclick="removeElement(this.parentNode.parentNode)">Remove Grade</button>
        </fieldset>
    `; // sets html for new Grade div, input field for course name
    totalGrades.appendChild(gradeDiv); // add gradeDiv to the totalGrades div
}

function removeElement(fieldset) {
    // Directly removing the parent fieldset which can be a course, category, or assignment
    fieldset.remove();
}

