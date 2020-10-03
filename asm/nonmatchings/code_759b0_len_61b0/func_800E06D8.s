.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E06D8
/* 79B88 800E06D8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 79B8C 800E06DC AFB10014 */  sw        $s1, 0x14($sp)
/* 79B90 800E06E0 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* 79B94 800E06E4 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* 79B98 800E06E8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 79B9C 800E06EC AFB20018 */  sw        $s2, 0x18($sp)
/* 79BA0 800E06F0 AFB00010 */  sw        $s0, 0x10($sp)
/* 79BA4 800E06F4 8E2400C8 */  lw        $a0, 0xc8($s1)
/* 79BA8 800E06F8 862200C0 */  lh        $v0, 0xc0($s1)
/* 79BAC 800E06FC 863200C6 */  lh        $s2, 0xc6($s1)
/* 79BB0 800E0700 1440003F */  bnez      $v0, .L800E0800
/* 79BB4 800E0704 0000102D */   daddu    $v0, $zero, $zero
/* 79BB8 800E0708 82220015 */  lb        $v0, 0x15($s1)
/* 79BBC 800E070C 1440003C */  bnez      $v0, .L800E0800
/* 79BC0 800E0710 0000102D */   daddu    $v0, $zero, $zero
/* 79BC4 800E0714 3C028016 */  lui       $v0, 0x8016
/* 79BC8 800E0718 8442A562 */  lh        $v0, -0x5a9e($v0)
/* 79BCC 800E071C 2405FFFF */  addiu     $a1, $zero, -1
/* 79BD0 800E0720 14450003 */  bne       $v0, $a1, .L800E0730
/* 79BD4 800E0724 3C020200 */   lui      $v0, 0x200
.L800E0728:
/* 79BD8 800E0728 08038200 */  j         .L800E0800
/* 79BDC 800E072C 0000102D */   daddu    $v0, $zero, $zero
.L800E0730:
/* 79BE0 800E0730 8E230000 */  lw        $v1, ($s1)
/* 79BE4 800E0734 34422000 */  ori       $v0, $v0, 0x2000
/* 79BE8 800E0738 00621824 */  and       $v1, $v1, $v0
/* 79BEC 800E073C 3C020200 */  lui       $v0, 0x200
/* 79BF0 800E0740 14620009 */  bne       $v1, $v0, .L800E0768
/* 79BF4 800E0744 00000000 */   nop      
/* 79BF8 800E0748 10800007 */  beqz      $a0, .L800E0768
/* 79BFC 800E074C 3C031000 */   lui      $v1, 0x1000
/* 79C00 800E0750 8C820000 */  lw        $v0, ($a0)
/* 79C04 800E0754 00431024 */  and       $v0, $v0, $v1
/* 79C08 800E0758 10400003 */  beqz      $v0, .L800E0768
/* 79C0C 800E075C 00000000 */   nop      
/* 79C10 800E0760 080381FF */  j         .L800E07FC
/* 79C14 800E0764 A62500C6 */   sh       $a1, 0xc6($s1)
.L800E0768:
/* 79C18 800E0768 3C108016 */  lui       $s0, 0x8016
/* 79C1C 800E076C 8610A562 */  lh        $s0, -0x5a9e($s0)
/* 79C20 800E0770 32024000 */  andi      $v0, $s0, 0x4000
/* 79C24 800E0774 14400007 */  bnez      $v0, .L800E0794
/* 79C28 800E0778 00000000 */   nop      
/* 79C2C 800E077C 0C05173A */  jal       func_80145CE8
/* 79C30 800E0780 0200202D */   daddu    $a0, $s0, $zero
/* 79C34 800E0784 1440000E */  bnez      $v0, .L800E07C0
/* 79C38 800E0788 0000102D */   daddu    $v0, $zero, $zero
/* 79C3C 800E078C 08038200 */  j         .L800E0800
/* 79C40 800E0790 00000000 */   nop      
.L800E0794:
/* 79C44 800E0794 0C0394BE */  jal       func_800E52F8
/* 79C48 800E0798 00000000 */   nop      
/* 79C4C 800E079C 14400003 */  bnez      $v0, .L800E07AC
/* 79C50 800E07A0 2402FFFF */   addiu    $v0, $zero, -1
/* 79C54 800E07A4 080381CA */  j         .L800E0728
/* 79C58 800E07A8 A62200C6 */   sh       $v0, 0xc6($s1)
.L800E07AC:
/* 79C5C 800E07AC 0C0441A9 */  jal       get_entity_type
/* 79C60 800E07B0 0200202D */   daddu    $a0, $s0, $zero
/* 79C64 800E07B4 2403000C */  addiu     $v1, $zero, 0xc
/* 79C68 800E07B8 10430011 */  beq       $v0, $v1, .L800E0800
/* 79C6C 800E07BC 0000102D */   daddu    $v0, $zero, $zero
.L800E07C0:
/* 79C70 800E07C0 16500008 */  bne       $s2, $s0, .L800E07E4
/* 79C74 800E07C4 3C03F7FF */   lui      $v1, 0xf7ff
/* 79C78 800E07C8 8E220000 */  lw        $v0, ($s1)
/* 79C7C 800E07CC 3C030800 */  lui       $v1, 0x800
/* 79C80 800E07D0 00431024 */  and       $v0, $v0, $v1
/* 79C84 800E07D4 10400007 */  beqz      $v0, .L800E07F4
/* 79C88 800E07D8 0000102D */   daddu    $v0, $zero, $zero
/* 79C8C 800E07DC 08038200 */  j         .L800E0800
/* 79C90 800E07E0 00000000 */   nop      
.L800E07E4:
/* 79C94 800E07E4 8E220000 */  lw        $v0, ($s1)
/* 79C98 800E07E8 3463FFFF */  ori       $v1, $v1, 0xffff
/* 79C9C 800E07EC 00431024 */  and       $v0, $v0, $v1
/* 79CA0 800E07F0 AE220000 */  sw        $v0, ($s1)
.L800E07F4:
/* 79CA4 800E07F4 2402FFFF */  addiu     $v0, $zero, -1
/* 79CA8 800E07F8 A62200C6 */  sh        $v0, 0xc6($s1)
.L800E07FC:
/* 79CAC 800E07FC 24020001 */  addiu     $v0, $zero, 1
.L800E0800:
/* 79CB0 800E0800 8FBF001C */  lw        $ra, 0x1c($sp)
/* 79CB4 800E0804 8FB20018 */  lw        $s2, 0x18($sp)
/* 79CB8 800E0808 8FB10014 */  lw        $s1, 0x14($sp)
/* 79CBC 800E080C 8FB00010 */  lw        $s0, 0x10($sp)
/* 79CC0 800E0810 03E00008 */  jr        $ra
/* 79CC4 800E0814 27BD0020 */   addiu    $sp, $sp, 0x20
