.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802422EC_A1D3EC
/* A1D3EC 802422EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A1D3F0 802422F0 AFBF0010 */  sw        $ra, 0x10($sp)
/* A1D3F4 802422F4 8C82000C */  lw        $v0, 0xc($a0)
/* A1D3F8 802422F8 0C0B1EAF */  jal       get_variable
/* A1D3FC 802422FC 8C450000 */   lw       $a1, ($v0)
/* A1D400 80242300 0C0B1059 */  jal       does_script_exist
/* A1D404 80242304 0040202D */   daddu    $a0, $v0, $zero
/* A1D408 80242308 2C420001 */  sltiu     $v0, $v0, 1
/* A1D40C 8024230C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A1D410 80242310 00021040 */  sll       $v0, $v0, 1
/* A1D414 80242314 03E00008 */  jr        $ra
/* A1D418 80242318 27BD0018 */   addiu    $sp, $sp, 0x18
