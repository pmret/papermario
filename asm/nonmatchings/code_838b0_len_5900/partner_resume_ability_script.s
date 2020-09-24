.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel partner_resume_ability_script
/* 84D10 800EB860 3C028011 */  lui       $v0, 0x8011
/* 84D14 800EB864 8C42CFD8 */  lw        $v0, -0x3028($v0)
/* 84D18 800EB868 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 84D1C 800EB86C AFBF0014 */  sw        $ra, 0x14($sp)
/* 84D20 800EB870 10400009 */  beqz      $v0, .L800EB898
/* 84D24 800EB874 AFB00010 */   sw       $s0, 0x10($sp)
/* 84D28 800EB878 3C108011 */  lui       $s0, 0x8011
/* 84D2C 800EB87C 2610CFDC */  addiu     $s0, $s0, -0x3024
/* 84D30 800EB880 0C0B1059 */  jal       does_script_exist
/* 84D34 800EB884 8E040000 */   lw       $a0, ($s0)
/* 84D38 800EB888 10400003 */  beqz      $v0, .L800EB898
/* 84D3C 800EB88C 00000000 */   nop      
/* 84D40 800EB890 0C0B1123 */  jal       resume_all_script
/* 84D44 800EB894 8E040000 */   lw       $a0, ($s0)
.L800EB898:
/* 84D48 800EB898 8FBF0014 */  lw        $ra, 0x14($sp)
/* 84D4C 800EB89C 8FB00010 */  lw        $s0, 0x10($sp)
/* 84D50 800EB8A0 03E00008 */  jr        $ra
/* 84D54 800EB8A4 27BD0018 */   addiu    $sp, $sp, 0x18
