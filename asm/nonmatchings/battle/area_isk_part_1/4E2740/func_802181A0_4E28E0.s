.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802181A0_4E28E0
/* 4E28E0 802181A0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4E28E4 802181A4 AFB10014 */  sw        $s1, 0x14($sp)
/* 4E28E8 802181A8 0080882D */  daddu     $s1, $a0, $zero
/* 4E28EC 802181AC AFBF0020 */  sw        $ra, 0x20($sp)
/* 4E28F0 802181B0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4E28F4 802181B4 AFB20018 */  sw        $s2, 0x18($sp)
/* 4E28F8 802181B8 AFB00010 */  sw        $s0, 0x10($sp)
/* 4E28FC 802181BC 8E30000C */  lw        $s0, 0xc($s1)
/* 4E2900 802181C0 8E050000 */  lw        $a1, ($s0)
/* 4E2904 802181C4 0C0B1EAF */  jal       get_variable
/* 4E2908 802181C8 26100004 */   addiu    $s0, $s0, 4
/* 4E290C 802181CC 8E050000 */  lw        $a1, ($s0)
/* 4E2910 802181D0 26100004 */  addiu     $s0, $s0, 4
/* 4E2914 802181D4 0220202D */  daddu     $a0, $s1, $zero
/* 4E2918 802181D8 0C0B1EAF */  jal       get_variable
/* 4E291C 802181DC 0040982D */   daddu    $s3, $v0, $zero
/* 4E2920 802181E0 8E050000 */  lw        $a1, ($s0)
/* 4E2924 802181E4 26100004 */  addiu     $s0, $s0, 4
/* 4E2928 802181E8 0220202D */  daddu     $a0, $s1, $zero
/* 4E292C 802181EC 0C0B1EAF */  jal       get_variable
/* 4E2930 802181F0 0040902D */   daddu    $s2, $v0, $zero
/* 4E2934 802181F4 0220202D */  daddu     $a0, $s1, $zero
/* 4E2938 802181F8 8E050000 */  lw        $a1, ($s0)
/* 4E293C 802181FC 0C0B1EAF */  jal       get_variable
/* 4E2940 80218200 0040802D */   daddu    $s0, $v0, $zero
/* 4E2944 80218204 8E240148 */  lw        $a0, 0x148($s1)
/* 4E2948 80218208 0C09A75B */  jal       get_actor
/* 4E294C 8021820C 0040882D */   daddu    $s1, $v0, $zero
/* 4E2950 80218210 0040182D */  daddu     $v1, $v0, $zero
/* 4E2954 80218214 8C620008 */  lw        $v0, 8($v1)
/* 4E2958 80218218 90420024 */  lbu       $v0, 0x24($v0)
/* 4E295C 8021821C 8C640008 */  lw        $a0, 8($v1)
/* 4E2960 80218220 02629823 */  subu      $s3, $s3, $v0
/* 4E2964 80218224 A0730194 */  sb        $s3, 0x194($v1)
/* 4E2968 80218228 90820025 */  lbu       $v0, 0x25($a0)
/* 4E296C 8021822C 02429023 */  subu      $s2, $s2, $v0
/* 4E2970 80218230 A0720195 */  sb        $s2, 0x195($v1)
/* 4E2974 80218234 90820026 */  lbu       $v0, 0x26($a0)
/* 4E2978 80218238 02028023 */  subu      $s0, $s0, $v0
/* 4E297C 8021823C A0700196 */  sb        $s0, 0x196($v1)
/* 4E2980 80218240 90840027 */  lbu       $a0, 0x27($a0)
/* 4E2984 80218244 02248823 */  subu      $s1, $s1, $a0
/* 4E2988 80218248 A0710197 */  sb        $s1, 0x197($v1)
/* 4E298C 8021824C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 4E2990 80218250 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4E2994 80218254 8FB20018 */  lw        $s2, 0x18($sp)
/* 4E2998 80218258 8FB10014 */  lw        $s1, 0x14($sp)
/* 4E299C 8021825C 8FB00010 */  lw        $s0, 0x10($sp)
/* 4E29A0 80218260 24020002 */  addiu     $v0, $zero, 2
/* 4E29A4 80218264 03E00008 */  jr        $ra
/* 4E29A8 80218268 27BD0028 */   addiu    $sp, $sp, 0x28
/* 4E29AC 8021826C 00000000 */  nop       
