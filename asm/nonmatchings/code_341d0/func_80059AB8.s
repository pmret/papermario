.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80059AB8
/* 34EB8 80059AB8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 34EBC 80059ABC AFB50024 */  sw        $s5, 0x24($sp)
/* 34EC0 80059AC0 0080A82D */  daddu     $s5, $a0, $zero
/* 34EC4 80059AC4 00A0202D */  daddu     $a0, $a1, $zero
/* 34EC8 80059AC8 AFB60028 */  sw        $s6, 0x28($sp)
/* 34ECC 80059ACC 00C0B02D */  daddu     $s6, $a2, $zero
/* 34ED0 80059AD0 AFB40020 */  sw        $s4, 0x20($sp)
/* 34ED4 80059AD4 8FB40040 */  lw        $s4, 0x40($sp)
/* 34ED8 80059AD8 00073840 */  sll       $a3, $a3, 1
/* 34EDC 80059ADC AFB00010 */  sw        $s0, 0x10($sp)
/* 34EE0 80059AE0 00878021 */  addu      $s0, $a0, $a3
/* 34EE4 80059AE4 AFBF002C */  sw        $ra, 0x2c($sp)
/* 34EE8 80059AE8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 34EEC 80059AEC AFB20018 */  sw        $s2, 0x18($sp)
/* 34EF0 80059AF0 AFB10014 */  sw        $s1, 0x14($sp)
/* 34EF4 80059AF4 8EA20008 */  lw        $v0, 8($s5)
/* 34EF8 80059AF8 8EA30000 */  lw        $v1, ($s5)
/* 34EFC 80059AFC 00021040 */  sll       $v0, $v0, 1
/* 34F00 80059B00 00623021 */  addu      $a2, $v1, $v0
/* 34F04 80059B04 00D0102B */  sltu      $v0, $a2, $s0
/* 34F08 80059B08 1040001C */  beqz      $v0, .L80059B7C
/* 34F0C 80059B0C 0280902D */   daddu    $s2, $s4, $zero
/* 34F10 80059B10 26940008 */  addiu     $s4, $s4, 8
/* 34F14 80059B14 00C48823 */  subu      $s1, $a2, $a0
/* 34F18 80059B18 00118843 */  sra       $s1, $s1, 1
/* 34F1C 80059B1C 00118840 */  sll       $s1, $s1, 1
/* 34F20 80059B20 32230FFF */  andi      $v1, $s1, 0xfff
/* 34F24 80059B24 00031B00 */  sll       $v1, $v1, 0xc
/* 34F28 80059B28 32C20FFF */  andi      $v0, $s6, 0xfff
/* 34F2C 80059B2C 3C130400 */  lui       $s3, 0x400
/* 34F30 80059B30 00531025 */  or        $v0, $v0, $s3
/* 34F34 80059B34 00621825 */  or        $v1, $v1, $v0
/* 34F38 80059B38 02068023 */  subu      $s0, $s0, $a2
/* 34F3C 80059B3C 00108043 */  sra       $s0, $s0, 1
/* 34F40 80059B40 0C0187A4 */  jal       osVirtualToPhysical
/* 34F44 80059B44 AE430000 */   sw       $v1, ($s2)
/* 34F48 80059B48 AE420004 */  sw        $v0, 4($s2)
/* 34F4C 80059B4C 0280902D */  daddu     $s2, $s4, $zero
/* 34F50 80059B50 00108040 */  sll       $s0, $s0, 1
/* 34F54 80059B54 32100FFF */  andi      $s0, $s0, 0xfff
/* 34F58 80059B58 00108300 */  sll       $s0, $s0, 0xc
/* 34F5C 80059B5C 02D18821 */  addu      $s1, $s6, $s1
/* 34F60 80059B60 32310FFF */  andi      $s1, $s1, 0xfff
/* 34F64 80059B64 02338825 */  or        $s1, $s1, $s3
/* 34F68 80059B68 02118025 */  or        $s0, $s0, $s1
/* 34F6C 80059B6C AE500000 */  sw        $s0, ($s2)
/* 34F70 80059B70 8EA40000 */  lw        $a0, ($s5)
/* 34F74 80059B74 080166E7 */  j         .L80059B9C
/* 34F78 80059B78 26940008 */   addiu    $s4, $s4, 8
.L80059B7C:
/* 34F7C 80059B7C 26940008 */  addiu     $s4, $s4, 8
/* 34F80 80059B80 30E20FFF */  andi      $v0, $a3, 0xfff
/* 34F84 80059B84 00021300 */  sll       $v0, $v0, 0xc
/* 34F88 80059B88 32C30FFF */  andi      $v1, $s6, 0xfff
/* 34F8C 80059B8C 3C050400 */  lui       $a1, 0x400
/* 34F90 80059B90 00651825 */  or        $v1, $v1, $a1
/* 34F94 80059B94 00431025 */  or        $v0, $v0, $v1
/* 34F98 80059B98 AE420000 */  sw        $v0, ($s2)
.L80059B9C:
/* 34F9C 80059B9C 0C0187A4 */  jal       osVirtualToPhysical
/* 34FA0 80059BA0 00000000 */   nop
/* 34FA4 80059BA4 AE420004 */  sw        $v0, 4($s2)
/* 34FA8 80059BA8 0280102D */  daddu     $v0, $s4, $zero
/* 34FAC 80059BAC 8FBF002C */  lw        $ra, 0x2c($sp)
/* 34FB0 80059BB0 8FB60028 */  lw        $s6, 0x28($sp)
/* 34FB4 80059BB4 8FB50024 */  lw        $s5, 0x24($sp)
/* 34FB8 80059BB8 8FB40020 */  lw        $s4, 0x20($sp)
/* 34FBC 80059BBC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 34FC0 80059BC0 8FB20018 */  lw        $s2, 0x18($sp)
/* 34FC4 80059BC4 8FB10014 */  lw        $s1, 0x14($sp)
/* 34FC8 80059BC8 8FB00010 */  lw        $s0, 0x10($sp)
/* 34FCC 80059BCC 03E00008 */  jr        $ra
/* 34FD0 80059BD0 27BD0030 */   addiu    $sp, $sp, 0x30
