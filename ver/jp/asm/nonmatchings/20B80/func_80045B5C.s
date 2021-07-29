.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80045B5C
/* 20F5C 80045B5C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 20F60 80045B60 AFB00028 */  sw        $s0, 0x28($sp)
/* 20F64 80045B64 0080802D */  daddu     $s0, $a0, $zero
/* 20F68 80045B68 AFBF002C */  sw        $ra, 0x2c($sp)
/* 20F6C 80045B6C 86030012 */  lh        $v1, 0x12($s0)
/* 20F70 80045B70 10600005 */  beqz      $v1, .L80045B88
/* 20F74 80045B74 24020001 */   addiu    $v0, $zero, 1
/* 20F78 80045B78 10620011 */  beq       $v1, $v0, .L80045BC0
/* 20F7C 80045B7C 00000000 */   nop
/* 20F80 80045B80 08011710 */  j         .L80045C40
/* 20F84 80045B84 00000000 */   nop
.L80045B88:
/* 20F88 80045B88 82020017 */  lb        $v0, 0x17($s0)
/* 20F8C 80045B8C 1040002C */  beqz      $v0, .L80045C40
/* 20F90 80045B90 00000000 */   nop
/* 20F94 80045B94 86020012 */  lh        $v0, 0x12($s0)
/* 20F98 80045B98 A2000017 */  sb        $zero, 0x17($s0)
/* 20F9C 80045B9C 00021080 */  sll       $v0, $v0, 2
/* 20FA0 80045BA0 3C048008 */  lui       $a0, %hi(D_80078130)
/* 20FA4 80045BA4 00822021 */  addu      $a0, $a0, $v0
/* 20FA8 80045BA8 8C848130 */  lw        $a0, %lo(D_80078130)($a0)
/* 20FAC 80045BAC 0C04ADB5 */  jal       func_8012B6D4
/* 20FB0 80045BB0 0000282D */   daddu    $a1, $zero, $zero
/* 20FB4 80045BB4 24470017 */  addiu     $a3, $v0, 0x17
/* 20FB8 80045BB8 080116FD */  j         .L80045BF4
/* 20FBC 80045BBC 2403002D */   addiu    $v1, $zero, 0x2d
.L80045BC0:
/* 20FC0 80045BC0 82020017 */  lb        $v0, 0x17($s0)
/* 20FC4 80045BC4 1040001E */  beqz      $v0, .L80045C40
/* 20FC8 80045BC8 00000000 */   nop
/* 20FCC 80045BCC 86020012 */  lh        $v0, 0x12($s0)
/* 20FD0 80045BD0 A2000017 */  sb        $zero, 0x17($s0)
/* 20FD4 80045BD4 00021080 */  sll       $v0, $v0, 2
/* 20FD8 80045BD8 3C048008 */  lui       $a0, %hi(D_80078130)
/* 20FDC 80045BDC 00822021 */  addu      $a0, $a0, $v0
/* 20FE0 80045BE0 8C848130 */  lw        $a0, %lo(D_80078130)($a0)
/* 20FE4 80045BE4 0C04ADB5 */  jal       func_8012B6D4
/* 20FE8 80045BE8 0000282D */   daddu    $a1, $zero, $zero
/* 20FEC 80045BEC 24470017 */  addiu     $a3, $v0, 0x17
/* 20FF0 80045BF0 2403001C */  addiu     $v1, $zero, 0x1c
.L80045BF4:
/* 20FF4 80045BF4 24040009 */  addiu     $a0, $zero, 9
/* 20FF8 80045BF8 00072FC2 */  srl       $a1, $a3, 0x1f
/* 20FFC 80045BFC 00E52821 */  addu      $a1, $a3, $a1
/* 21000 80045C00 00052843 */  sra       $a1, $a1, 1
/* 21004 80045C04 240200A0 */  addiu     $v0, $zero, 0xa0
/* 21008 80045C08 00452823 */  subu      $a1, $v0, $a1
/* 2100C 80045C0C 24060050 */  addiu     $a2, $zero, 0x50
/* 21010 80045C10 3C028004 */  lui       $v0, %hi(func_80045B0C)
/* 21014 80045C14 24425B0C */  addiu     $v0, $v0, %lo(func_80045B0C)
/* 21018 80045C18 AFA20018 */  sw        $v0, 0x18($sp)
/* 2101C 80045C1C 2402FFFF */  addiu     $v0, $zero, -1
/* 21020 80045C20 AFA30010 */  sw        $v1, 0x10($sp)
/* 21024 80045C24 AFA00014 */  sw        $zero, 0x14($sp)
/* 21028 80045C28 AFB0001C */  sw        $s0, 0x1c($sp)
/* 2102C 80045C2C 0C05335E */  jal       func_8014CD78
/* 21030 80045C30 AFA20020 */   sw       $v0, 0x20($sp)
/* 21034 80045C34 24040009 */  addiu     $a0, $zero, 9
/* 21038 80045C38 0C0533CB */  jal       func_8014CF2C
/* 2103C 80045C3C 24050001 */   addiu    $a1, $zero, 1
.L80045C40:
/* 21040 80045C40 8FBF002C */  lw        $ra, 0x2c($sp)
/* 21044 80045C44 8FB00028 */  lw        $s0, 0x28($sp)
/* 21048 80045C48 03E00008 */  jr        $ra
/* 2104C 80045C4C 27BD0030 */   addiu    $sp, $sp, 0x30
