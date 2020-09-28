.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8013A888
/* D0F88 8013A888 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D0F8C 8013A88C 2C82005A */  sltiu     $v0, $a0, 0x5a
/* D0F90 8013A890 AFBF0018 */  sw        $ra, 0x18($sp)
/* D0F94 8013A894 AFB10014 */  sw        $s1, 0x14($sp)
/* D0F98 8013A898 1040000C */  beqz      $v0, .L8013A8CC
/* D0F9C 8013A89C AFB00010 */   sw       $s0, 0x10($sp)
/* D0FA0 8013A8A0 2411FFFF */  addiu     $s1, $zero, -1
.L8013A8A4:
/* D0FA4 8013A8A4 00041140 */  sll       $v0, $a0, 5
/* D0FA8 8013A8A8 00441023 */  subu      $v0, $v0, $a0
/* D0FAC 8013A8AC 3C038015 */  lui       $v1, 0x8015
/* D0FB0 8013A8B0 8C636954 */  lw        $v1, 0x6954($v1)
/* D0FB4 8013A8B4 00021080 */  sll       $v0, $v0, 2
/* D0FB8 8013A8B8 00431021 */  addu      $v0, $v0, $v1
/* D0FBC 8013A8BC 0C04EA15 */  jal       func_8013A854
/* D0FC0 8013A8C0 84500010 */   lh       $s0, 0x10($v0)
/* D0FC4 8013A8C4 1611FFF7 */  bne       $s0, $s1, .L8013A8A4
/* D0FC8 8013A8C8 0200202D */   daddu    $a0, $s0, $zero
.L8013A8CC:
/* D0FCC 8013A8CC 8FBF0018 */  lw        $ra, 0x18($sp)
/* D0FD0 8013A8D0 8FB10014 */  lw        $s1, 0x14($sp)
/* D0FD4 8013A8D4 8FB00010 */  lw        $s0, 0x10($sp)
/* D0FD8 8013A8D8 03E00008 */  jr        $ra
/* D0FDC 8013A8DC 27BD0020 */   addiu    $sp, $sp, 0x20
