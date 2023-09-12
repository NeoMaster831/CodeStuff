class Student:
    def __init__(self, id, na, ge):
        self.id = id
        self.name = na
        self.gender = ge
    def printMajor(self):
        if self.id//100%10 == 6:
            print("Nigger방어과")
        else:
            print("병신")

a = Student(1601, '강태준이', '남')
