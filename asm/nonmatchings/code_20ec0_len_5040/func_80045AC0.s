.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80045AC0
/* 20EC0 80045AC0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 20EC4 80045AC4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 20EC8 80045AC8 0000202D */  daddu     $a0, $zero, $zero
/* 20ECC 80045ACC 3C03800A */  lui       $v1, %hi(D_800A0BC0)
/* 20ED0 80045AD0 24630BC0 */  addiu     $v1, $v1, %lo(D_800A0BC0)
.L80045AD4:
/* 20ED4 80045AD4 A4600010 */  sh        $zero, 0x10($v1)
/* 20ED8 80045AD8 AC600018 */  sw        $zero, 0x18($v1)
/* 20EDC 80045ADC 24840001 */  addiu     $a0, $a0, 1
/* 20EE0 80045AE0 28820020 */  slti      $v0, $a0, 0x20
/* 20EE4 80045AE4 1440FFFB */  bnez      $v0, .L80045AD4
/* 20EE8 80045AE8 2463001C */   addiu    $v1, $v1, 0x1c
/* 20EEC 80045AEC 3C058004 */  lui       $a1, %hi(D_80045BC8)
/* 20EF0 80045AF0 24A55BC8 */  addiu     $a1, $a1, %lo(D_80045BC8)
/* 20EF4 80045AF4 0C048C56 */  jal       bind_dynamic_entity_3
/* 20EF8 80045AF8 0000202D */   daddu    $a0, $zero, $zero
/* 20EFC 80045AFC 0C0117ED */  jal       func_80045FB4
/* 20F00 80045B00 00000000 */   nop      
/* 20F04 80045B04 8FBF0010 */  lw        $ra, 0x10($sp)
/* 20F08 80045B08 03E00008 */  jr        $ra
/* 20F0C 80045B0C 27BD0018 */   addiu    $sp, $sp, 0x18
