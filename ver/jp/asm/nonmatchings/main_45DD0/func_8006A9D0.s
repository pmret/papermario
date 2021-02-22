.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006A9D0
/* 45DD0 8006A9D0 3C1A8007 */  lui       $k0, %hi(func_8006A9E0)
/* 45DD4 8006A9D4 275AA9E0 */  addiu     $k0, $k0, %lo(func_8006A9E0)
/* 45DD8 8006A9D8 03400008 */  jr        $k0
/* 45DDC 8006A9DC 00000000 */   nop
