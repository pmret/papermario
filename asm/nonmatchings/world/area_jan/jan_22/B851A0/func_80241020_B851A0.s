.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241020_B851A0
/* B851A0 80241020 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B851A4 80241024 AFB1001C */  sw        $s1, 0x1c($sp)
/* B851A8 80241028 0080882D */  daddu     $s1, $a0, $zero
/* B851AC 8024102C AFBF0020 */  sw        $ra, 0x20($sp)
/* B851B0 80241030 AFB00018 */  sw        $s0, 0x18($sp)
/* B851B4 80241034 8E30000C */  lw        $s0, 0xc($s1)
/* B851B8 80241038 8E020000 */  lw        $v0, ($s0)
/* B851BC 8024103C 1040001B */  beqz      $v0, .L802410AC
/* B851C0 80241040 26100004 */   addiu    $s0, $s0, 4
/* B851C4 80241044 8E050000 */  lw        $a1, ($s0)
/* B851C8 80241048 0C0B1EAF */  jal       get_variable
/* B851CC 8024104C 26100004 */   addiu    $s0, $s0, 4
/* B851D0 80241050 AE220070 */  sw        $v0, 0x70($s1)
/* B851D4 80241054 8E050000 */  lw        $a1, ($s0)
/* B851D8 80241058 26100004 */  addiu     $s0, $s0, 4
/* B851DC 8024105C 0C0B1EAF */  jal       get_variable
/* B851E0 80241060 0220202D */   daddu    $a0, $s1, $zero
/* B851E4 80241064 AE220074 */  sw        $v0, 0x74($s1)
/* B851E8 80241068 8E050000 */  lw        $a1, ($s0)
/* B851EC 8024106C 0C0B1EAF */  jal       get_variable
/* B851F0 80241070 0220202D */   daddu    $a0, $s1, $zero
/* B851F4 80241074 24040168 */  addiu     $a0, $zero, 0x168
/* B851F8 80241078 0000282D */  daddu     $a1, $zero, $zero
/* B851FC 8024107C C6200070 */  lwc1      $f0, 0x70($s1)
/* B85200 80241080 46800020 */  cvt.s.w   $f0, $f0
/* B85204 80241084 C6220074 */  lwc1      $f2, 0x74($s1)
/* B85208 80241088 468010A0 */  cvt.s.w   $f2, $f2
/* B8520C 8024108C 44060000 */  mfc1      $a2, $f0
/* B85210 80241090 44071000 */  mfc1      $a3, $f2
/* B85214 80241094 44820000 */  mtc1      $v0, $f0
/* B85218 80241098 00000000 */  nop       
/* B8521C 8024109C 46800020 */  cvt.s.w   $f0, $f0
/* B85220 802410A0 AE220078 */  sw        $v0, 0x78($s1)
/* B85224 802410A4 0C05267B */  jal       func_801499EC
/* B85228 802410A8 E7A00010 */   swc1     $f0, 0x10($sp)
.L802410AC:
/* B8522C 802410AC 8FBF0020 */  lw        $ra, 0x20($sp)
/* B85230 802410B0 8FB1001C */  lw        $s1, 0x1c($sp)
/* B85234 802410B4 8FB00018 */  lw        $s0, 0x18($sp)
/* B85238 802410B8 24020002 */  addiu     $v0, $zero, 2
/* B8523C 802410BC 03E00008 */  jr        $ra
/* B85240 802410C0 27BD0028 */   addiu    $sp, $sp, 0x28
