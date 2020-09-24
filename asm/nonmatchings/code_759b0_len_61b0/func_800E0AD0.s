.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E0AD0
/* 79F80 800E0AD0 3C02800F */  lui       $v0, 0x800f
/* 79F84 800E0AD4 8C427B30 */  lw        $v0, 0x7b30($v0)
/* 79F88 800E0AD8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 79F8C 800E0ADC AFBF0010 */  sw        $ra, 0x10($sp)
/* 79F90 800E0AE0 8C420004 */  lw        $v0, 4($v0)
/* 79F94 800E0AE4 30420010 */  andi      $v0, $v0, 0x10
/* 79F98 800E0AE8 10400007 */  beqz      $v0, .L800E0B08
/* 79F9C 800E0AEC 00000000 */   nop      
/* 79FA0 800E0AF0 3C028011 */  lui       $v0, 0x8011
/* 79FA4 800E0AF4 8C42C958 */  lw        $v0, -0x36a8($v0)
/* 79FA8 800E0AF8 10400003 */  beqz      $v0, .L800E0B08
/* 79FAC 800E0AFC 00000000 */   nop      
/* 79FB0 800E0B00 0C0ADC7A */  jal       func_802B71E8
/* 79FB4 800E0B04 00000000 */   nop      
.L800E0B08:
/* 79FB8 800E0B08 8FBF0010 */  lw        $ra, 0x10($sp)
/* 79FBC 800E0B0C 03E00008 */  jr        $ra
/* 79FC0 800E0B10 27BD0018 */   addiu    $sp, $sp, 0x18
