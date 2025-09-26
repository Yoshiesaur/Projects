class Dist_Grades:
    '''
    This class is the rock bottom of the program. It will hold the distribution 
    of grades of EACH course. Meaning each Dist_Grades class is either a quiz, homework, test, etc.
    
    get_average()               -> Returns the weighted average of the specified subject column -- function returns a decimal number
    re_adjust()                 -> Re-adjusts the weight of the specified subject column        -- function does not return anything
    add_grade(name, grade)      -> Adds a grade and a name to the grade for user clarity        -- function does not return anything
    remove_grade(name, grade)   -> Removes specific name and grade                              -- function does not return anything
    
    '''
    def __init__(self, name, weight, average_w = None, grades = None, obj_name = None): 
        self.name = name
        self.weight = weight
        self.average_w = average_w if average_w is not None else 0
        self.grades = grades if grades is not None else []
        self.obj_name = obj_name if obj_name is not None else []
        
    def get_average(self) -> float:
        return self.average_w
    
    def re_adjust(self):
        # Base -> No values for array 'grades'
        if self.grades is None or len(self.grades) == 0:
            self.average_w = 0
            return
        # Case -> Clear 'average_w' -> Calculate weighted average
        self.average_w = 0
        sum = 0
        iter = 0
        # Iterates through the size of 'grades' and sets new weighted average
        for idx in range(len(self.grades)):
            sum += self.grades[idx]
            iter += 1
        self.average_w = sum / iter
        
    def add_grade(self, in_name, in_grade):
        self.obj_name.append(in_name)
        self.grades.append(in_grade)
        self.re_adjust()
        
    def remove_grade(self, tar_name, tar_grade) -> str:
        # Base -> No items in lists
        if not self.grades or not self.obj_name:
            return "No items in list"
        
        for idx in range(len(self.grades)):
            if (self.grades[idx] == tar_grade) and (self.obj_name[idx] == tar_name):
                del self.grades[idx]
                del self.obj_name[idx]
                self.re_adjust()
                return f"Removed '{tar_name}' with grade {tar_grade}"
            
        return "No matching entries found."
                
class Subject:
    
    # Constructor
    def __init__(self, in_name):
        self.sub_name = in_name
        self.columns = None if not None else Dist_Grades
        
        