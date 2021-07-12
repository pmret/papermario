.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024004C_DE87BC
/* DE87BC 8024004C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* DE87C0 80240050 AFB20020 */  sw        $s2, 0x20($sp)
/* DE87C4 80240054 0080902D */  daddu     $s2, $a0, $zero
/* DE87C8 80240058 AFBF0024 */  sw        $ra, 0x24($sp)
/* DE87CC 8024005C AFB1001C */  sw        $s1, 0x1c($sp)
/* DE87D0 80240060 AFB00018 */  sw        $s0, 0x18($sp)
/* DE87D4 80240064 10A0004A */  beqz      $a1, .L80240190
/* DE87D8 80240068 8E51000C */   lw       $s1, 0xc($s2)
/* DE87DC 8024006C 0C00AB39 */  jal       heap_malloc
/* DE87E0 80240070 24040058 */   addiu    $a0, $zero, 0x58
/* DE87E4 80240074 0000202D */  daddu     $a0, $zero, $zero
/* DE87E8 80240078 3C05FD05 */  lui       $a1, 0xfd05
/* DE87EC 8024007C 34A50F81 */  ori       $a1, $a1, 0xf81
/* DE87F0 80240080 0040802D */  daddu     $s0, $v0, $zero
/* DE87F4 80240084 0200302D */  daddu     $a2, $s0, $zero
/* DE87F8 80240088 0C0B2026 */  jal       set_variable
/* DE87FC 8024008C AE500084 */   sw       $s0, 0x84($s2)
/* DE8800 80240090 8E250000 */  lw        $a1, ($s1)
/* DE8804 80240094 26310004 */  addiu     $s1, $s1, 4
/* DE8808 80240098 0C0B1EAF */  jal       get_variable
/* DE880C 8024009C 0240202D */   daddu    $a0, $s2, $zero
/* DE8810 802400A0 AE020038 */  sw        $v0, 0x38($s0)
/* DE8814 802400A4 8E250000 */  lw        $a1, ($s1)
/* DE8818 802400A8 26310004 */  addiu     $s1, $s1, 4
/* DE881C 802400AC 0C0B1EAF */  jal       get_variable
/* DE8820 802400B0 0240202D */   daddu    $a0, $s2, $zero
/* DE8824 802400B4 AE02003C */  sw        $v0, 0x3c($s0)
/* DE8828 802400B8 8E250000 */  lw        $a1, ($s1)
/* DE882C 802400BC 26310004 */  addiu     $s1, $s1, 4
/* DE8830 802400C0 0C0B210B */  jal       get_float_variable
/* DE8834 802400C4 0240202D */   daddu    $a0, $s2, $zero
/* DE8838 802400C8 E600000C */  swc1      $f0, 0xc($s0)
/* DE883C 802400CC 8E250000 */  lw        $a1, ($s1)
/* DE8840 802400D0 26310004 */  addiu     $s1, $s1, 4
/* DE8844 802400D4 0C0B210B */  jal       get_float_variable
/* DE8848 802400D8 0240202D */   daddu    $a0, $s2, $zero
/* DE884C 802400DC E6000010 */  swc1      $f0, 0x10($s0)
/* DE8850 802400E0 8E250000 */  lw        $a1, ($s1)
/* DE8854 802400E4 26310004 */  addiu     $s1, $s1, 4
/* DE8858 802400E8 0C0B210B */  jal       get_float_variable
/* DE885C 802400EC 0240202D */   daddu    $a0, $s2, $zero
/* DE8860 802400F0 E6000014 */  swc1      $f0, 0x14($s0)
/* DE8864 802400F4 8E250000 */  lw        $a1, ($s1)
/* DE8868 802400F8 26310004 */  addiu     $s1, $s1, 4
/* DE886C 802400FC 0C0B210B */  jal       get_float_variable
/* DE8870 80240100 0240202D */   daddu    $a0, $s2, $zero
/* DE8874 80240104 E6000018 */  swc1      $f0, 0x18($s0)
/* DE8878 80240108 8E250000 */  lw        $a1, ($s1)
/* DE887C 8024010C 26310004 */  addiu     $s1, $s1, 4
/* DE8880 80240110 0C0B210B */  jal       get_float_variable
/* DE8884 80240114 0240202D */   daddu    $a0, $s2, $zero
/* DE8888 80240118 E600001C */  swc1      $f0, 0x1c($s0)
/* DE888C 8024011C 8E250000 */  lw        $a1, ($s1)
/* DE8890 80240120 26310004 */  addiu     $s1, $s1, 4
/* DE8894 80240124 0C0B210B */  jal       get_float_variable
/* DE8898 80240128 0240202D */   daddu    $a0, $s2, $zero
/* DE889C 8024012C E6000020 */  swc1      $f0, 0x20($s0)
/* DE88A0 80240130 8E250000 */  lw        $a1, ($s1)
/* DE88A4 80240134 26310004 */  addiu     $s1, $s1, 4
/* DE88A8 80240138 0C0B210B */  jal       get_float_variable
/* DE88AC 8024013C 0240202D */   daddu    $a0, $s2, $zero
/* DE88B0 80240140 E6000024 */  swc1      $f0, 0x24($s0)
/* DE88B4 80240144 8E250000 */  lw        $a1, ($s1)
/* DE88B8 80240148 0C0B210B */  jal       get_float_variable
/* DE88BC 8024014C 0240202D */   daddu    $a0, $s2, $zero
/* DE88C0 80240150 3C013F80 */  lui       $at, 0x3f80
/* DE88C4 80240154 44811000 */  mtc1      $at, $f2
/* DE88C8 80240158 E6000028 */  swc1      $f0, 0x28($s0)
/* DE88CC 8024015C AFA00014 */  sw        $zero, 0x14($sp)
/* DE88D0 80240160 E7A20010 */  swc1      $f2, 0x10($sp)
/* DE88D4 80240164 8E05000C */  lw        $a1, 0xc($s0)
/* DE88D8 80240168 8E060010 */  lw        $a2, 0x10($s0)
/* DE88DC 8024016C 8E070014 */  lw        $a3, 0x14($s0)
/* DE88E0 80240170 0C01CA6C */  jal       playFX_83
/* DE88E4 80240174 24040002 */   addiu    $a0, $zero, 2
/* DE88E8 80240178 AE020050 */  sw        $v0, 0x50($s0)
/* DE88EC 8024017C A600004E */  sh        $zero, 0x4e($s0)
/* DE88F0 80240180 A6000048 */  sh        $zero, 0x48($s0)
/* DE88F4 80240184 A600004A */  sh        $zero, 0x4a($s0)
/* DE88F8 80240188 A6000044 */  sh        $zero, 0x44($s0)
/* DE88FC 8024018C A6000046 */  sh        $zero, 0x46($s0)
.L80240190:
/* DE8900 80240190 8FBF0024 */  lw        $ra, 0x24($sp)
/* DE8904 80240194 8FB20020 */  lw        $s2, 0x20($sp)
/* DE8908 80240198 8FB1001C */  lw        $s1, 0x1c($sp)
/* DE890C 8024019C 8FB00018 */  lw        $s0, 0x18($sp)
/* DE8910 802401A0 24020002 */  addiu     $v0, $zero, 2
/* DE8914 802401A4 03E00008 */  jr        $ra
/* DE8918 802401A8 27BD0028 */   addiu    $sp, $sp, 0x28
