.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412F4
/* A683F4 802412F4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A683F8 802412F8 3C05FE36 */  lui       $a1, 0xfe36
/* A683FC 802412FC AFBF0010 */  sw        $ra, 0x10($sp)
/* A68400 80241300 8C820148 */  lw        $v0, 0x148($a0)
/* A68404 80241304 3C06800B */  lui       $a2, 0x800b
/* A68408 80241308 8CC60F9C */  lw        $a2, 0xf9c($a2)
/* A6840C 8024130C 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A68410 80241310 00C23026 */  xor       $a2, $a2, $v0
/* A68414 80241314 0C0B2026 */  jal       set_variable
/* A68418 80241318 2CC60001 */   sltiu    $a2, $a2, 1
/* A6841C 8024131C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A68420 80241320 24020002 */  addiu     $v0, $zero, 2
/* A68424 80241324 03E00008 */  jr        $ra
/* A68428 80241328 27BD0018 */   addiu    $sp, $sp, 0x18
/* A6842C 8024132C 00000000 */  nop       
