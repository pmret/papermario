.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_CD7320
/* CD7320 80240040 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CD7324 80240044 AFBF0010 */  sw        $ra, 0x10($sp)
/* CD7328 80240048 8C82000C */  lw        $v0, 0xc($a0)
/* CD732C 8024004C 3C068016 */  lui       $a2, %hi(gCollisionStatus+0x6)
/* CD7330 80240050 84C6A556 */  lh        $a2, %lo(gCollisionStatus+0x6)($a2)
/* CD7334 80240054 0C0B2026 */  jal       set_variable
/* CD7338 80240058 8C450000 */   lw       $a1, ($v0)
/* CD733C 8024005C 8FBF0010 */  lw        $ra, 0x10($sp)
/* CD7340 80240060 24020002 */  addiu     $v0, $zero, 2
/* CD7344 80240064 03E00008 */  jr        $ra
/* CD7348 80240068 27BD0018 */   addiu    $sp, $sp, 0x18
/* CD734C 8024006C 00000000 */  nop
