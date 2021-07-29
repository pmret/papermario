from dataclasses import dataclass

@dataclass
class AddressRange:
    start: int
    end: int
    
    def contains(self, addr: int) -> bool:
        return self.start <= addr < self.end