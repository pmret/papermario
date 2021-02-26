.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800556C8
/* 30AC8 800556C8 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 30ACC 800556CC AFB00030 */  sw        $s0, 0x30($sp)
/* 30AD0 800556D0 3C108008 */  lui       $s0, %hi(D_80078D80)
/* 30AD4 800556D4 26108D80 */  addiu     $s0, $s0, %lo(D_80078D80)
/* 30AD8 800556D8 8FA30048 */  lw        $v1, 0x48($sp)
/* 30ADC 800556DC 24020001 */  addiu     $v0, $zero, 1
/* 30AE0 800556E0 AFBF0034 */  sw        $ra, 0x34($sp)
/* 30AE4 800556E4 AE020000 */  sw        $v0, ($s0)
/* 30AE8 800556E8 AFA40010 */  sw        $a0, 0x10($sp)
/* 30AEC 800556EC 27A40010 */  addiu     $a0, $sp, 0x10
/* 30AF0 800556F0 AFA60014 */  sw        $a2, 0x14($sp)
/* 30AF4 800556F4 AFA70018 */  sw        $a3, 0x18($sp)
/* 30AF8 800556F8 AFA50020 */  sw        $a1, 0x20($sp)
/* 30AFC 800556FC AFA00024 */  sw        $zero, 0x24($sp)
/* 30B00 80055700 0C013524 */  jal       func_8004D490
/* 30B04 80055704 AFA3001C */   sw       $v1, 0x1c($sp)
/* 30B08 80055708 AE000000 */  sw        $zero, ($s0)
/* 30B0C 8005570C 8FBF0034 */  lw        $ra, 0x34($sp)
/* 30B10 80055710 8FB00030 */  lw        $s0, 0x30($sp)
/* 30B14 80055714 03E00008 */  jr        $ra
/* 30B18 80055718 27BD0038 */   addiu    $sp, $sp, 0x38
