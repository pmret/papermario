.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_DCCCD0
/* DCCCD0 80240000 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* DCCCD4 80240004 8C42EFC8 */  lw        $v0, %lo(gPlayerStatus)($v0)
/* DCCCD8 80240008 30420020 */  andi      $v0, $v0, 0x20
/* DCCCDC 8024000C 10400003 */  beqz      $v0, .L8024001C
/* DCCCE0 80240010 00000000 */   nop
.L80240014:
/* DCCCE4 80240014 03E00008 */  jr        $ra
/* DCCCE8 80240018 24020001 */   addiu    $v0, $zero, 1
.L8024001C:
/* DCCCEC 8024001C 3C028011 */  lui       $v0, %hi(D_8010EBB0)
/* DCCCF0 80240020 8042EBB0 */  lb        $v0, %lo(D_8010EBB0)($v0)
/* DCCCF4 80240024 10400009 */  beqz      $v0, .L8024004C
/* DCCCF8 80240028 00000000 */   nop
/* DCCCFC 8024002C 3C028011 */  lui       $v0, %hi(gPlayerData)
/* DCCD00 80240030 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* DCCD04 80240034 80430012 */  lb        $v1, 0x12($v0)
/* DCCD08 80240038 24020001 */  addiu     $v0, $zero, 1
/* DCCD0C 8024003C 1062FFF5 */  beq       $v1, $v0, .L80240014
/* DCCD10 80240040 24020007 */   addiu    $v0, $zero, 7
/* DCCD14 80240044 1062FFF3 */  beq       $v1, $v0, .L80240014
/* DCCD18 80240048 00000000 */   nop
.L8024004C:
/* DCCD1C 8024004C 03E00008 */  jr        $ra
/* DCCD20 80240050 0000102D */   daddu    $v0, $zero, $zero
