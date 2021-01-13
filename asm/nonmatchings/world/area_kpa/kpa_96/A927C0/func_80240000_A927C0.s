.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_A927C0
/* A927C0 80240000 3C028011 */  lui       $v0, %hi(gPlayerData+0xC)
/* A927C4 80240004 8442F29C */  lh        $v0, %lo(gPlayerData+0xC)($v0)
/* A927C8 80240008 18400003 */  blez      $v0, .L80240018
/* A927CC 8024000C 24020001 */   addiu    $v0, $zero, 1
/* A927D0 80240010 08090007 */  j         .L8024001C
/* A927D4 80240014 AC800084 */   sw       $zero, 0x84($a0)
.L80240018:
/* A927D8 80240018 AC820084 */  sw        $v0, 0x84($a0)
.L8024001C:
/* A927DC 8024001C 03E00008 */  jr        $ra
/* A927E0 80240020 24020002 */   addiu    $v0, $zero, 2
/* A927E4 80240024 00000000 */  nop
/* A927E8 80240028 00000000 */  nop
/* A927EC 8024002C 00000000 */  nop
