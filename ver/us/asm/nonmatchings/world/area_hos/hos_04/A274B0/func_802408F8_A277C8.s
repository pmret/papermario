.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408F8_A277C8
/* A277C8 802408F8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A277CC 802408FC 3C04800B */  lui       $a0, %hi(gCameras)
/* A277D0 80240900 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* A277D4 80240904 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* A277D8 80240908 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* A277DC 8024090C 3C05800A */  lui       $a1, %hi(nuGfxCfb_ptr)
/* A277E0 80240910 8CA5A64C */  lw        $a1, %lo(nuGfxCfb_ptr)($a1)
/* A277E4 80240914 3C088024 */  lui       $t0, %hi(D_80241B80_A28A50)
/* A277E8 80240918 25081B80 */  addiu     $t0, $t0, %lo(D_80241B80_A28A50)
/* A277EC 8024091C AFBF0020 */  sw        $ra, 0x20($sp)
/* A277F0 80240920 AFB1001C */  sw        $s1, 0x1c($sp)
/* A277F4 80240924 AFB00018 */  sw        $s0, 0x18($sp)
/* A277F8 80240928 00031080 */  sll       $v0, $v1, 2
/* A277FC 8024092C 00431021 */  addu      $v0, $v0, $v1
/* A27800 80240930 00021080 */  sll       $v0, $v0, 2
/* A27804 80240934 00431023 */  subu      $v0, $v0, $v1
/* A27808 80240938 000218C0 */  sll       $v1, $v0, 3
/* A2780C 8024093C 00431021 */  addu      $v0, $v0, $v1
/* A27810 80240940 000210C0 */  sll       $v0, $v0, 3
/* A27814 80240944 8D030000 */  lw        $v1, ($t0)
/* A27818 80240948 10A30013 */  beq       $a1, $v1, .L80240998
/* A2781C 8024094C 00448821 */   addu     $s1, $v0, $a0
/* A27820 80240950 3C108024 */  lui       $s0, %hi(D_80241B7C_A28A4C)
/* A27824 80240954 26101B7C */  addiu     $s0, $s0, %lo(D_80241B7C_A28A4C)
/* A27828 80240958 3C01442F */  lui       $at, 0x442f
/* A2782C 8024095C 44816000 */  mtc1      $at, $f12
/* A27830 80240960 3C014396 */  lui       $at, 0x4396
/* A27834 80240964 44817000 */  mtc1      $at, $f14
/* A27838 80240968 8E060000 */  lw        $a2, ($s0)
/* A2783C 8024096C 3C073F99 */  lui       $a3, 0x3f99
/* A27840 80240970 34E7999A */  ori       $a3, $a3, 0x999a
/* A27844 80240974 AD050000 */  sw        $a1, ($t0)
/* A27848 80240978 0C0901A5 */  jal       func_80240694_A27564
/* A2784C 8024097C AFB00010 */   sw       $s0, 0x10($sp)
/* A27850 80240980 0000102D */  daddu     $v0, $zero, $zero
/* A27854 80240984 C6000000 */  lwc1      $f0, ($s0)
/* A27858 80240988 24030001 */  addiu     $v1, $zero, 1
/* A2785C 8024098C A6230506 */  sh        $v1, 0x506($s1)
/* A27860 80240990 08090267 */  j         .L8024099C
/* A27864 80240994 E62004DC */   swc1     $f0, 0x4dc($s1)
.L80240998:
/* A27868 80240998 0000102D */  daddu     $v0, $zero, $zero
.L8024099C:
/* A2786C 8024099C 8FBF0020 */  lw        $ra, 0x20($sp)
/* A27870 802409A0 8FB1001C */  lw        $s1, 0x1c($sp)
/* A27874 802409A4 8FB00018 */  lw        $s0, 0x18($sp)
/* A27878 802409A8 03E00008 */  jr        $ra
/* A2787C 802409AC 27BD0028 */   addiu    $sp, $sp, 0x28
