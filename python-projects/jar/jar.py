class Jar:
    def __init__(self, capacity):
        self.capacity = capacity
        self.cookies = 0

    def __str__(self):
        return "🍪" * self.cookies

    def deposit(self, n):
        if self.cookies + n > self.capacity:
            raise ValueError
        self.cookies += n

    def withdraw(self, n):
        if self.cookies - n < 0:
            raise ValueError
        self.cookies -= n

    @property
    def capacity(self):
        return self.capacity

    @property
    def size(self):
        return self.cookies

jar = Jar(12)

print(jar.__str__())

jar.deposit(5)

print(jar.__str__())

