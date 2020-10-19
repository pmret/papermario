.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_9A4650
/* 9A4650 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9A4654 80240004 3C038016 */  lui       $v1, 0x8016
/* 9A4658 80240008 8463A550 */  lh        $v1, -0x5ab0($v1)
/* 9A465C 8024000C 24020023 */  addiu     $v0, $zero, 0x23
/* 9A4660 80240010 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9A4664 80240014 8C85000C */  lw        $a1, 0xc($a0)
/* 9A4668 80240018 14620005 */  bne       $v1, $v0, .L80240030
/* 9A466C 8024001C 0000302D */   daddu    $a2, $zero, $zero
/* 9A4670 80240020 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 9A4674 80240024 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 9A4678 80240028 80420040 */  lb        $v0, 0x40($v0)
/* 9A467C 8024002C 000237C2 */  srl       $a2, $v0, 0x1f
.L80240030:
/* 9A4680 80240030 24020025 */  addiu     $v0, $zero, 0x25
/* 9A4684 80240034 14620006 */  bne       $v1, $v0, .L80240050
/* 9A4688 80240038 00000000 */   nop      
/* 9A468C 8024003C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 9A4690 80240040 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 9A4694 80240044 80420040 */  lb        $v0, 0x40($v0)
/* 9A4698 80240048 5C400001 */  bgtzl     $v0, .L80240050
/* 9A469C 8024004C 24060002 */   addiu    $a2, $zero, 2
.L80240050:
/* 9A46A0 80240050 8CA50000 */  lw        $a1, ($a1)
/* 9A46A4 80240054 0C0B2026 */  jal       set_variable
/* 9A46A8 80240058 00000000 */   nop      
/* 9A46AC 8024005C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9A46B0 80240060 24020002 */  addiu     $v0, $zero, 2
/* 9A46B4 80240064 03E00008 */  jr        $ra
/* 9A46B8 80240068 27BD0018 */   addiu    $sp, $sp, 0x18
