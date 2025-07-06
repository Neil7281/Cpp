def ordered_configuration(configuration: str):
    parts = configuration.split('|')
    config_map = {}
    indices = set()
    
    for part in parts:
        if len(part) < 14:  # Ensuring minimum length for valid config (4-digit index + 10-char value)
            return ["Invalid configuration"]
        index, value = part[:4], part[4:]
        
        # Validation conditions
        if index == "0000" or not index.isdigit():
            return ["Invalid configuration"]
        if index in indices:
            return ["Invalid configuration"]
        if value in config_map.values():
            return ["Invalid configuration"]
        if len(value) != 10 or not value.isalnum():
            return ["Invalid configuration"]

        config_map[int(index)] = value
        indices.add(index)

    sorted_indices = sorted(config_map.keys())
    
    # Ensure indices are consecutive and start from 1
    if sorted_indices != list(range(1, len(sorted_indices) + 1)):
        return ["Invalid configuration"]

    return [config_map[i] for i in sorted_indices]

# Example test cases
print(ordered_configuration("0001LAJ5KBX9H8|0003UKURNK403F|0002M06K1Z9WFA|00040WRXZFMS2C"))  # Expected: ['76a3a4d214', 'f7c22e7904', '05d29f4a4b']
print(ordered_configuration("0002f7c22e7904|000176a3a4d214|0002 05d29f4a4b"))  # Expected: ['Invalid configuration']
print(ordered_configuration("0000f7c22e7904|000176a3a4d214|000305d29f4a4b"))  # Expected: ['Invalid configuration']