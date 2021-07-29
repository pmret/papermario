.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407E8_A1B8E8
/* A1B8E8 802407E8 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* A1B8EC 802407EC 0000202D */  daddu     $a0, $zero, $zero
/* A1B8F0 802407F0 27A50010 */  addiu     $a1, $sp, 0x10
/* A1B8F4 802407F4 27A60014 */  addiu     $a2, $sp, 0x14
/* A1B8F8 802407F8 27A70018 */  addiu     $a3, $sp, 0x18
/* A1B8FC 802407FC AFBF0034 */  sw        $ra, 0x34($sp)
/* A1B900 80240800 AFB40030 */  sw        $s4, 0x30($sp)
/* A1B904 80240804 AFB3002C */  sw        $s3, 0x2c($sp)
/* A1B908 80240808 AFB20028 */  sw        $s2, 0x28($sp)
/* A1B90C 8024080C AFB10024 */  sw        $s1, 0x24($sp)
/* A1B910 80240810 0C0470AC */  jal       mdl_get_copied_vertices
/* A1B914 80240814 AFB00020 */   sw       $s0, 0x20($sp)
/* A1B918 80240818 8FA20018 */  lw        $v0, 0x18($sp)
/* A1B91C 8024081C 1840002A */  blez      $v0, .L802408C8
/* A1B920 80240820 0000802D */   daddu    $s0, $zero, $zero
/* A1B924 80240824 3C145555 */  lui       $s4, 0x5555
/* A1B928 80240828 36945556 */  ori       $s4, $s4, 0x5556
/* A1B92C 8024082C 0200982D */  daddu     $s3, $s0, $zero
.L80240830:
/* A1B930 80240830 02140018 */  mult      $s0, $s4
/* A1B934 80240834 00101FC3 */  sra       $v1, $s0, 0x1f
/* A1B938 80240838 00004810 */  mfhi      $t1
/* A1B93C 8024083C 01231823 */  subu      $v1, $t1, $v1
/* A1B940 80240840 00031040 */  sll       $v0, $v1, 1
/* A1B944 80240844 00431021 */  addu      $v0, $v0, $v1
/* A1B948 80240848 02021023 */  subu      $v0, $s0, $v0
/* A1B94C 8024084C 3C038024 */  lui       $v1, %hi(D_80243BD2_A1ECD2)
/* A1B950 80240850 94633BD2 */  lhu       $v1, %lo(D_80243BD2_A1ECD2)($v1)
/* A1B954 80240854 24420001 */  addiu     $v0, $v0, 1
/* A1B958 80240858 00620018 */  mult      $v1, $v0
/* A1B95C 8024085C 8FA20014 */  lw        $v0, 0x14($sp)
/* A1B960 80240860 00102900 */  sll       $a1, $s0, 4
/* A1B964 80240864 00459021 */  addu      $s2, $v0, $a1
/* A1B968 80240868 00001812 */  mflo      $v1
/* A1B96C 8024086C 00732021 */  addu      $a0, $v1, $s3
/* A1B970 80240870 8FA30010 */  lw        $v1, 0x10($sp)
/* A1B974 80240874 3084FFFF */  andi      $a0, $a0, 0xffff
/* A1B978 80240878 0C01917C */  jal       sins
/* A1B97C 8024087C 00658821 */   addu     $s1, $v1, $a1
/* A1B980 80240880 00021400 */  sll       $v0, $v0, 0x10
/* A1B984 80240884 00021403 */  sra       $v0, $v0, 0x10
/* A1B988 80240888 00021840 */  sll       $v1, $v0, 1
/* A1B98C 8024088C 00621821 */  addu      $v1, $v1, $v0
/* A1B990 80240890 000318C0 */  sll       $v1, $v1, 3
/* A1B994 80240894 00621821 */  addu      $v1, $v1, $v0
/* A1B998 80240898 00031040 */  sll       $v0, $v1, 1
/* A1B99C 8024089C 04420001 */  bltzl     $v0, .L802408A4
/* A1B9A0 802408A0 24427FFF */   addiu    $v0, $v0, 0x7fff
.L802408A4:
/* A1B9A4 802408A4 26732AAA */  addiu     $s3, $s3, 0x2aaa
/* A1B9A8 802408A8 26100001 */  addiu     $s0, $s0, 1
/* A1B9AC 802408AC 000213C3 */  sra       $v0, $v0, 0xf
/* A1B9B0 802408B0 96230002 */  lhu       $v1, 2($s1)
/* A1B9B4 802408B4 8FA40018 */  lw        $a0, 0x18($sp)
/* A1B9B8 802408B8 00621821 */  addu      $v1, $v1, $v0
/* A1B9BC 802408BC 0204202A */  slt       $a0, $s0, $a0
/* A1B9C0 802408C0 1480FFDB */  bnez      $a0, .L80240830
/* A1B9C4 802408C4 A6430002 */   sh       $v1, 2($s2)
.L802408C8:
/* A1B9C8 802408C8 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* A1B9CC 802408CC 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* A1B9D0 802408D0 8C620000 */  lw        $v0, ($v1)
/* A1B9D4 802408D4 0000202D */  daddu     $a0, $zero, $zero
/* A1B9D8 802408D8 0040802D */  daddu     $s0, $v0, $zero
/* A1B9DC 802408DC 24420008 */  addiu     $v0, $v0, 8
/* A1B9E0 802408E0 AC620000 */  sw        $v0, ($v1)
/* A1B9E4 802408E4 3C02DE00 */  lui       $v0, 0xde00
/* A1B9E8 802408E8 0C0470BB */  jal       mdl_get_copied_gfx
/* A1B9EC 802408EC AE020000 */   sw       $v0, ($s0)
/* A1B9F0 802408F0 3C048024 */  lui       $a0, %hi(D_80243BD2_A1ECD2)
/* A1B9F4 802408F4 24843BD2 */  addiu     $a0, $a0, %lo(D_80243BD2_A1ECD2)
/* A1B9F8 802408F8 94830000 */  lhu       $v1, ($a0)
/* A1B9FC 802408FC AE020004 */  sw        $v0, 4($s0)
/* A1BA00 80240900 246300A3 */  addiu     $v1, $v1, 0xa3
/* A1BA04 80240904 A4830000 */  sh        $v1, ($a0)
/* A1BA08 80240908 8FBF0034 */  lw        $ra, 0x34($sp)
/* A1BA0C 8024090C 8FB40030 */  lw        $s4, 0x30($sp)
/* A1BA10 80240910 8FB3002C */  lw        $s3, 0x2c($sp)
/* A1BA14 80240914 8FB20028 */  lw        $s2, 0x28($sp)
/* A1BA18 80240918 8FB10024 */  lw        $s1, 0x24($sp)
/* A1BA1C 8024091C 8FB00020 */  lw        $s0, 0x20($sp)
/* A1BA20 80240920 03E00008 */  jr        $ra
/* A1BA24 80240924 27BD0038 */   addiu    $sp, $sp, 0x38
