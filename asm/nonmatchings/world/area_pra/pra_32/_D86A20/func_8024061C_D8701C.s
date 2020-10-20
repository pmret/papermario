.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024061C_D8701C
/* D8701C 8024061C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* D87020 80240620 AFB20020 */  sw        $s2, 0x20($sp)
/* D87024 80240624 0080902D */  daddu     $s2, $a0, $zero
/* D87028 80240628 AFBF0024 */  sw        $ra, 0x24($sp)
/* D8702C 8024062C AFB1001C */  sw        $s1, 0x1c($sp)
/* D87030 80240630 AFB00018 */  sw        $s0, 0x18($sp)
/* D87034 80240634 10A00035 */  beqz      $a1, .L8024070C
/* D87038 80240638 8E51000C */   lw       $s1, 0xc($s2)
/* D8703C 8024063C 0C00AB39 */  jal       heap_malloc
/* D87040 80240640 24040058 */   addiu    $a0, $zero, 0x58
/* D87044 80240644 0040802D */  daddu     $s0, $v0, $zero
/* D87048 80240648 AE500084 */  sw        $s0, 0x84($s2)
/* D8704C 8024064C 8E250000 */  lw        $a1, ($s1)
/* D87050 80240650 26310004 */  addiu     $s1, $s1, 4
/* D87054 80240654 0C0B1EAF */  jal       get_variable
/* D87058 80240658 0240202D */   daddu    $a0, $s2, $zero
/* D8705C 8024065C AE020038 */  sw        $v0, 0x38($s0)
/* D87060 80240660 8E250000 */  lw        $a1, ($s1)
/* D87064 80240664 26310004 */  addiu     $s1, $s1, 4
/* D87068 80240668 0C0B210B */  jal       get_float_variable
/* D8706C 8024066C 0240202D */   daddu    $a0, $s2, $zero
/* D87070 80240670 E6000018 */  swc1      $f0, 0x18($s0)
/* D87074 80240674 8E250000 */  lw        $a1, ($s1)
/* D87078 80240678 26310004 */  addiu     $s1, $s1, 4
/* D8707C 8024067C 0C0B210B */  jal       get_float_variable
/* D87080 80240680 0240202D */   daddu    $a0, $s2, $zero
/* D87084 80240684 E6000024 */  swc1      $f0, 0x24($s0)
/* D87088 80240688 8E250000 */  lw        $a1, ($s1)
/* D8708C 8024068C 26310004 */  addiu     $s1, $s1, 4
/* D87090 80240690 0C0B210B */  jal       get_float_variable
/* D87094 80240694 0240202D */   daddu    $a0, $s2, $zero
/* D87098 80240698 E6000020 */  swc1      $f0, 0x20($s0)
/* D8709C 8024069C 8E250000 */  lw        $a1, ($s1)
/* D870A0 802406A0 0C0B210B */  jal       get_float_variable
/* D870A4 802406A4 0240202D */   daddu    $a0, $s2, $zero
/* D870A8 802406A8 3C013F80 */  lui       $at, 0x3f80
/* D870AC 802406AC 44811000 */  mtc1      $at, $f2
/* D870B0 802406B0 E6000028 */  swc1      $f0, 0x28($s0)
/* D870B4 802406B4 AFA00014 */  sw        $zero, 0x14($sp)
/* D870B8 802406B8 E7A20010 */  swc1      $f2, 0x10($sp)
/* D870BC 802406BC 8E050018 */  lw        $a1, 0x18($s0)
/* D870C0 802406C0 8E060024 */  lw        $a2, 0x24($s0)
/* D870C4 802406C4 8E070020 */  lw        $a3, 0x20($s0)
/* D870C8 802406C8 0C01C9AC */  jal       func_800726B0
/* D870CC 802406CC 24040001 */   addiu    $a0, $zero, 1
/* D870D0 802406D0 AE020054 */  sw        $v0, 0x54($s0)
/* D870D4 802406D4 8C43000C */  lw        $v1, 0xc($v0)
/* D870D8 802406D8 9202003B */  lbu       $v0, 0x3b($s0)
/* D870DC 802406DC A0620034 */  sb        $v0, 0x34($v1)
/* D870E0 802406E0 8E020054 */  lw        $v0, 0x54($s0)
/* D870E4 802406E4 8C42000C */  lw        $v0, 0xc($v0)
/* D870E8 802406E8 AC400020 */  sw        $zero, 0x20($v0)
/* D870EC 802406EC 8E050018 */  lw        $a1, 0x18($s0)
/* D870F0 802406F0 8E060028 */  lw        $a2, 0x28($s0)
/* D870F4 802406F4 8E070020 */  lw        $a3, 0x20($s0)
/* D870F8 802406F8 0C044898 */  jal       create_shadow_type
/* D870FC 802406FC 0000202D */   daddu    $a0, $zero, $zero
/* D87100 80240700 AE020040 */  sw        $v0, 0x40($s0)
/* D87104 80240704 2402010E */  addiu     $v0, $zero, 0x10e
/* D87108 80240708 A602004C */  sh        $v0, 0x4c($s0)
.L8024070C:
/* D8710C 8024070C 8FBF0024 */  lw        $ra, 0x24($sp)
/* D87110 80240710 8FB20020 */  lw        $s2, 0x20($sp)
/* D87114 80240714 8FB1001C */  lw        $s1, 0x1c($sp)
/* D87118 80240718 8FB00018 */  lw        $s0, 0x18($sp)
/* D8711C 8024071C 24020002 */  addiu     $v0, $zero, 2
/* D87120 80240720 03E00008 */  jr        $ra
/* D87124 80240724 27BD0028 */   addiu    $sp, $sp, 0x28
