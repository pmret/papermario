opts = {}

def initialize(config):
    global opts
    opts = config.get("options")
    
def set(opt, val):
    opts[opt] = val
    
def get(opt, default=None):
    return opts.get(opt, default)

def mode_active(mode):
    return mode in opts["modes"] or "all" in opts["modes"]