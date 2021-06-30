class Range:

    def __init__(self, start=None, end=None):
        self.start = start
        self.end = end
    
    def has_start(self):
        return self.start is not None
    
    def has_end(self):
        return self.end is not None
    
    def is_complete(self):
        return self.has_start() and self.has_end()
