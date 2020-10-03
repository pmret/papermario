.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80244F44
/* 1657A4 80244F44 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1657A8 80244F48 0080382D */  daddu     $a3, $a0, $zero
/* 1657AC 80244F4C AFB00018 */  sw        $s0, 0x18($sp)
/* 1657B0 80244F50 00A0802D */  daddu     $s0, $a1, $zero
/* 1657B4 80244F54 AFB1001C */  sw        $s1, 0x1c($sp)
/* 1657B8 80244F58 AFBF0020 */  sw        $ra, 0x20($sp)
/* 1657BC 80244F5C 80E30004 */  lb        $v1, 4($a3)
/* 1657C0 80244F60 24020002 */  addiu     $v0, $zero, 2
/* 1657C4 80244F64 10620016 */  beq       $v1, $v0, .L80244FC0
/* 1657C8 80244F68 00C0882D */   daddu    $s1, $a2, $zero
/* 1657CC 80244F6C 3C0400FF */  lui       $a0, 0xff
/* 1657D0 80244F70 3484FF00 */  ori       $a0, $a0, 0xff00
/* 1657D4 80244F74 3C030002 */  lui       $v1, 2
/* 1657D8 80244F78 8CE20000 */  lw        $v0, ($a3)
/* 1657DC 80244F7C 34630200 */  ori       $v1, $v1, 0x200
/* 1657E0 80244F80 00441024 */  and       $v0, $v0, $a0
/* 1657E4 80244F84 14430004 */  bne       $v0, $v1, .L80244F98
/* 1657E8 80244F88 24040037 */   addiu    $a0, $zero, 0x37
/* 1657EC 80244F8C 26050008 */  addiu     $a1, $s0, 8
/* 1657F0 80244F90 0C090B80 */  jal       func_80242E00
/* 1657F4 80244F94 26260008 */   addiu    $a2, $s1, 8
.L80244F98:
/* 1657F8 80244F98 0C0926A9 */  jal       func_80249AA4
/* 1657FC 80244F9C 2404000A */   addiu    $a0, $zero, 0xa
/* 165800 80244FA0 0040202D */  daddu     $a0, $v0, $zero
/* 165804 80244FA4 26050014 */  addiu     $a1, $s0, 0x14
/* 165808 80244FA8 26260002 */  addiu     $a2, $s1, 2
/* 16580C 80244FAC 24020001 */  addiu     $v0, $zero, 1
/* 165810 80244FB0 240700FF */  addiu     $a3, $zero, 0xff
/* 165814 80244FB4 AFA00010 */  sw        $zero, 0x10($sp)
/* 165818 80244FB8 0C09265F */  jal       func_8024997C
/* 16581C 80244FBC AFA20014 */   sw       $v0, 0x14($sp)
.L80244FC0:
/* 165820 80244FC0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 165824 80244FC4 8FB1001C */  lw        $s1, 0x1c($sp)
/* 165828 80244FC8 8FB00018 */  lw        $s0, 0x18($sp)
/* 16582C 80244FCC 03E00008 */  jr        $ra
/* 165830 80244FD0 27BD0028 */   addiu    $sp, $sp, 0x28
