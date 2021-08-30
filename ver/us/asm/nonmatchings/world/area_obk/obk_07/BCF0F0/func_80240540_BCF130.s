.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240540_BCF130
/* BCF130 80240540 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BCF134 80240544 3C05FD05 */  lui       $a1, 0xfd05
/* BCF138 80240548 34A50F86 */  ori       $a1, $a1, 0xf86
/* BCF13C 8024054C AFBF0010 */  sw        $ra, 0x10($sp)
/* BCF140 80240550 0C0B1EAF */  jal       evt_get_variable
/* BCF144 80240554 0000202D */   daddu    $a0, $zero, $zero
/* BCF148 80240558 8FBF0010 */  lw        $ra, 0x10($sp)
/* BCF14C 8024055C 03E00008 */  jr        $ra
/* BCF150 80240560 27BD0018 */   addiu    $sp, $sp, 0x18
