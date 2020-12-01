.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E2FD0
/* 104850 802E2FD0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 104854 802E2FD4 AFB1001C */  sw        $s1, 0x1c($sp)
/* 104858 802E2FD8 0080882D */  daddu     $s1, $a0, $zero
/* 10485C 802E2FDC AFBF0020 */  sw        $ra, 0x20($sp)
/* 104860 802E2FE0 AFB00018 */  sw        $s0, 0x18($sp)
/* 104864 802E2FE4 92240004 */  lbu       $a0, 4($s1)
/* 104868 802E2FE8 0C0441A9 */  jal       get_entity_type
/* 10486C 802E2FEC 0000802D */   daddu    $s0, $zero, $zero
/* 104870 802E2FF0 2443FFF3 */  addiu     $v1, $v0, -0xd
/* 104874 802E2FF4 2C62000E */  sltiu     $v0, $v1, 0xe
/* 104878 802E2FF8 1040001A */  beqz      $v0, .L802E3064
/* 10487C 802E2FFC 00031080 */   sll      $v0, $v1, 2
/* 104880 802E3000 3C01802F */  lui       $at, %hi(D_802EB198)
/* 104884 802E3004 00220821 */  addu      $at, $at, $v0
/* 104888 802E3008 8C22B198 */  lw        $v0, %lo(D_802EB198)($at)
/* 10488C 802E300C 00400008 */  jr        $v0
/* 104890 802E3010 00000000 */   nop      
/* 104894 802E3014 3C10802F */  lui       $s0, %hi(D_802E9C8C)
/* 104898 802E3018 080B8C19 */  j         .L802E3064
/* 10489C 802E301C 26109C8C */   addiu    $s0, $s0, %lo(D_802E9C8C)
/* 1048A0 802E3020 3C10802F */  lui       $s0, %hi(D_802E9CF8)
/* 1048A4 802E3024 080B8C19 */  j         .L802E3064
/* 1048A8 802E3028 26109CF8 */   addiu    $s0, $s0, %lo(D_802E9CF8)
/* 1048AC 802E302C 3C10802F */  lui       $s0, %hi(D_802E9CB0)
/* 1048B0 802E3030 080B8C19 */  j         .L802E3064
/* 1048B4 802E3034 26109CB0 */   addiu    $s0, $s0, %lo(D_802E9CB0)
/* 1048B8 802E3038 3C10802F */  lui       $s0, %hi(D_802E9D1C)
/* 1048BC 802E303C 080B8C19 */  j         .L802E3064
/* 1048C0 802E3040 26109D1C */   addiu    $s0, $s0, %lo(D_802E9D1C)
/* 1048C4 802E3044 3C10802F */  lui       $s0, %hi(D_802E9CD4)
/* 1048C8 802E3048 080B8C19 */  j         .L802E3064
/* 1048CC 802E304C 26109CD4 */   addiu    $s0, $s0, %lo(D_802E9CD4)
/* 1048D0 802E3050 3C10802F */  lui       $s0, %hi(D_802E9D40)
/* 1048D4 802E3054 080B8C19 */  j         .L802E3064
/* 1048D8 802E3058 26109D40 */   addiu    $s0, $s0, %lo(D_802E9D40)
/* 1048DC 802E305C 3C10802F */  lui       $s0, %hi(D_802E9D64)
/* 1048E0 802E3060 26109D64 */  addiu     $s0, $s0, %lo(D_802E9D64)
.L802E3064:
/* 1048E4 802E3064 1200000E */  beqz      $s0, .L802E30A0
/* 1048E8 802E3068 0200202D */   daddu    $a0, $s0, $zero
/* 1048EC 802E306C C6200048 */  lwc1      $f0, 0x48($s1)
/* 1048F0 802E3070 C622004C */  lwc1      $f2, 0x4c($s1)
/* 1048F4 802E3074 C6240050 */  lwc1      $f4, 0x50($s1)
/* 1048F8 802E3078 3C028000 */  lui       $v0, 0x8000
/* 1048FC 802E307C AFA00010 */  sw        $zero, 0x10($sp)
/* 104900 802E3080 4600018D */  trunc.w.s $f6, $f0
/* 104904 802E3084 44053000 */  mfc1      $a1, $f6
/* 104908 802E3088 4600118D */  trunc.w.s $f6, $f2
/* 10490C 802E308C 44063000 */  mfc1      $a2, $f6
/* 104910 802E3090 4600218D */  trunc.w.s $f6, $f4
/* 104914 802E3094 44073000 */  mfc1      $a3, $f6
/* 104918 802E3098 0C044631 */  jal       create_entity
/* 10491C 802E309C AFA20014 */   sw       $v0, 0x14($sp)
.L802E30A0:
/* 104920 802E30A0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 104924 802E30A4 8FB1001C */  lw        $s1, 0x1c($sp)
/* 104928 802E30A8 8FB00018 */  lw        $s0, 0x18($sp)
/* 10492C 802E30AC 03E00008 */  jr        $ra
/* 104930 802E30B0 27BD0028 */   addiu    $sp, $sp, 0x28
/* 104934 802E30B4 00000000 */  nop       
/* 104938 802E30B8 00000000 */  nop       
/* 10493C 802E30BC 00000000 */  nop       
