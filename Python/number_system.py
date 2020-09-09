def twos_complement(input_value, num_bits):
    """Calculates a two's complement integer from the given input value's bits."""
    mask = 2 ** (num_bits - 1)
    return -(input_value & mask) + (input_value & ~mask)
    

print(twos_complement(5, 8))
	
    
    
    
    
