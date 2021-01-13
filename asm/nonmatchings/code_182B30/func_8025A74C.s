.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8025A74C
/* 18902C 8025A74C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 189030 8025A750 AFB40020 */  sw        $s4, 0x20($sp)
/* 189034 8025A754 0080A02D */  daddu     $s4, $a0, $zero
/* 189038 8025A758 AFB10014 */  sw        $s1, 0x14($sp)
/* 18903C 8025A75C 00A0882D */  daddu     $s1, $a1, $zero
/* 189040 8025A760 AFB20018 */  sw        $s2, 0x18($sp)
/* 189044 8025A764 00C0902D */  daddu     $s2, $a2, $zero
/* 189048 8025A768 AFBF0028 */  sw        $ra, 0x28($sp)
/* 18904C 8025A76C AFB50024 */  sw        $s5, 0x24($sp)
/* 189050 8025A770 AFB3001C */  sw        $s3, 0x1c($sp)
/* 189054 8025A774 AFB00010 */  sw        $s0, 0x10($sp)
/* 189058 8025A778 8E3000C0 */  lw        $s0, 0xc0($s1)
/* 18905C 8025A77C 820206C1 */  lb        $v0, 0x6c1($s0)
/* 189060 8025A780 8FB50040 */  lw        $s5, 0x40($sp)
/* 189064 8025A784 10400032 */  beqz      $v0, .L8025A850
/* 189068 8025A788 00E0982D */   daddu    $s3, $a3, $zero
/* 18906C 8025A78C 16800017 */  bnez      $s4, .L8025A7EC
/* 189070 8025A790 00000000 */   nop
/* 189074 8025A794 0C0B7830 */  jal       func_802DE0C0
/* 189078 8025A798 96240088 */   lhu      $a0, 0x88($s1)
/* 18907C 8025A79C AE0206D0 */  sw        $v0, 0x6d0($s0)
/* 189080 8025A7A0 0040202D */  daddu     $a0, $v0, $zero
/* 189084 8025A7A4 A20006CD */  sb        $zero, 0x6cd($s0)
/* 189088 8025A7A8 8C830000 */  lw        $v1, ($a0)
/* 18908C 8025A7AC 2402FFFF */  addiu     $v0, $zero, -1
/* 189090 8025A7B0 50620023 */  beql      $v1, $v0, .L8025A840
/* 189094 8025A7B4 2402000A */   addiu    $v0, $zero, 0xa
/* 189098 8025A7B8 0080182D */  daddu     $v1, $a0, $zero
/* 18909C 8025A7BC 0040202D */  daddu     $a0, $v0, $zero
.L8025A7C0:
/* 1890A0 8025A7C0 920206CD */  lbu       $v0, 0x6cd($s0)
/* 1890A4 8025A7C4 24420001 */  addiu     $v0, $v0, 1
/* 1890A8 8025A7C8 A20206CD */  sb        $v0, 0x6cd($s0)
/* 1890AC 8025A7CC 00021600 */  sll       $v0, $v0, 0x18
/* 1890B0 8025A7D0 00021583 */  sra       $v0, $v0, 0x16
/* 1890B4 8025A7D4 00431021 */  addu      $v0, $v0, $v1
/* 1890B8 8025A7D8 8C420000 */  lw        $v0, ($v0)
/* 1890BC 8025A7DC 1444FFF8 */  bne       $v0, $a0, .L8025A7C0
/* 1890C0 8025A7E0 2402000A */   addiu    $v0, $zero, 0xa
/* 1890C4 8025A7E4 08096A11 */  j         .L8025A844
/* 1890C8 8025A7E8 A20006C2 */   sb       $zero, 0x6c2($s0)
.L8025A7EC:
/* 1890CC 8025A7EC 96240088 */  lhu       $a0, 0x88($s1)
/* 1890D0 8025A7F0 0C0B7A90 */  jal       func_802DEA40
/* 1890D4 8025A7F4 00000000 */   nop
/* 1890D8 8025A7F8 AE0206D0 */  sw        $v0, 0x6d0($s0)
/* 1890DC 8025A7FC 0040202D */  daddu     $a0, $v0, $zero
/* 1890E0 8025A800 A20006CD */  sb        $zero, 0x6cd($s0)
/* 1890E4 8025A804 8C830000 */  lw        $v1, ($a0)
/* 1890E8 8025A808 2402FFFF */  addiu     $v0, $zero, -1
/* 1890EC 8025A80C 5062000C */  beql      $v1, $v0, .L8025A840
/* 1890F0 8025A810 2402000A */   addiu    $v0, $zero, 0xa
/* 1890F4 8025A814 0080182D */  daddu     $v1, $a0, $zero
/* 1890F8 8025A818 0040202D */  daddu     $a0, $v0, $zero
.L8025A81C:
/* 1890FC 8025A81C 920206CD */  lbu       $v0, 0x6cd($s0)
/* 189100 8025A820 24420001 */  addiu     $v0, $v0, 1
/* 189104 8025A824 A20206CD */  sb        $v0, 0x6cd($s0)
/* 189108 8025A828 00021600 */  sll       $v0, $v0, 0x18
/* 18910C 8025A82C 00021583 */  sra       $v0, $v0, 0x16
/* 189110 8025A830 00431021 */  addu      $v0, $v0, $v1
/* 189114 8025A834 8C420000 */  lw        $v0, ($v0)
/* 189118 8025A838 1444FFF8 */  bne       $v0, $a0, .L8025A81C
/* 18911C 8025A83C 2402000A */   addiu    $v0, $zero, 0xa
.L8025A840:
/* 189120 8025A840 A20006C2 */  sb        $zero, 0x6c2($s0)
.L8025A844:
/* 189124 8025A844 A60006C8 */  sh        $zero, 0x6c8($s0)
/* 189128 8025A848 A60206CA */  sh        $v0, 0x6ca($s0)
/* 18912C 8025A84C A20006C1 */  sb        $zero, 0x6c1($s0)
.L8025A850:
/* 189130 8025A850 820206CD */  lb        $v0, 0x6cd($s0)
/* 189134 8025A854 1840002F */  blez      $v0, .L8025A914
/* 189138 8025A858 0000382D */   daddu    $a3, $zero, $zero
.L8025A85C:
/* 18913C 8025A85C 8E0206D0 */  lw        $v0, 0x6d0($s0)
/* 189140 8025A860 00071880 */  sll       $v1, $a3, 2
/* 189144 8025A864 00621821 */  addu      $v1, $v1, $v0
/* 189148 8025A868 00071140 */  sll       $v0, $a3, 5
/* 18914C 8025A86C 8C660000 */  lw        $a2, ($v1)
/* 189150 8025A870 10C00022 */  beqz      $a2, .L8025A8FC
/* 189154 8025A874 02025021 */   addu     $t2, $s0, $v0
/* 189158 8025A878 0000482D */  daddu     $t1, $zero, $zero
.L8025A87C:
/* 18915C 8025A87C 94C30000 */  lhu       $v1, ($a2)
/* 189160 8025A880 90C20001 */  lbu       $v0, 1($a2)
/* 189164 8025A884 24C60002 */  addiu     $a2, $a2, 2
/* 189168 8025A888 304B0001 */  andi      $t3, $v0, 1
/* 18916C 8025A88C 000312C2 */  srl       $v0, $v1, 0xb
/* 189170 8025A890 24450004 */  addiu     $a1, $v0, 4
/* 189174 8025A894 00031182 */  srl       $v0, $v1, 6
/* 189178 8025A898 3044001F */  andi      $a0, $v0, 0x1f
/* 18917C 8025A89C 00031842 */  srl       $v1, $v1, 1
/* 189180 8025A8A0 2CA20020 */  sltiu     $v0, $a1, 0x20
/* 189184 8025A8A4 14400002 */  bnez      $v0, .L8025A8B0
/* 189188 8025A8A8 3068001F */   andi     $t0, $v1, 0x1f
/* 18918C 8025A8AC 2405001F */  addiu     $a1, $zero, 0x1f
.L8025A8B0:
/* 189190 8025A8B0 24830004 */  addiu     $v1, $a0, 4
/* 189194 8025A8B4 2C620020 */  sltiu     $v0, $v1, 0x20
/* 189198 8025A8B8 50400001 */  beql      $v0, $zero, .L8025A8C0
/* 18919C 8025A8BC 2403001F */   addiu    $v1, $zero, 0x1f
.L8025A8C0:
/* 1891A0 8025A8C0 25040004 */  addiu     $a0, $t0, 4
/* 1891A4 8025A8C4 2C820020 */  sltiu     $v0, $a0, 0x20
/* 1891A8 8025A8C8 50400001 */  beql      $v0, $zero, .L8025A8D0
/* 1891AC 8025A8CC 2404001F */   addiu    $a0, $zero, 0x1f
.L8025A8D0:
/* 1891B0 8025A8D0 000512C0 */  sll       $v0, $a1, 0xb
/* 1891B4 8025A8D4 00031980 */  sll       $v1, $v1, 6
/* 1891B8 8025A8D8 00431025 */  or        $v0, $v0, $v1
/* 1891BC 8025A8DC 00041840 */  sll       $v1, $a0, 1
/* 1891C0 8025A8E0 00431025 */  or        $v0, $v0, $v1
/* 1891C4 8025A8E4 01621025 */  or        $v0, $t3, $v0
/* 1891C8 8025A8E8 A5420000 */  sh        $v0, ($t2)
/* 1891CC 8025A8EC 25290001 */  addiu     $t1, $t1, 1
/* 1891D0 8025A8F0 29220010 */  slti      $v0, $t1, 0x10
/* 1891D4 8025A8F4 1440FFE1 */  bnez      $v0, .L8025A87C
/* 1891D8 8025A8F8 254A0002 */   addiu    $t2, $t2, 2
.L8025A8FC:
/* 1891DC 8025A8FC 820206CD */  lb        $v0, 0x6cd($s0)
/* 1891E0 8025A900 24E70001 */  addiu     $a3, $a3, 1
/* 1891E4 8025A904 00E2102A */  slt       $v0, $a3, $v0
/* 1891E8 8025A908 1440FFD4 */  bnez      $v0, .L8025A85C
/* 1891EC 8025A90C 00000000 */   nop
/* 1891F0 8025A910 820206CD */  lb        $v0, 0x6cd($s0)
.L8025A914:
/* 1891F4 8025A914 1840000A */  blez      $v0, .L8025A940
/* 1891F8 8025A918 0000382D */   daddu    $a3, $zero, $zero
/* 1891FC 8025A91C 0200202D */  daddu     $a0, $s0, $zero
/* 189200 8025A920 0200182D */  daddu     $v1, $s0, $zero
.L8025A924:
/* 189204 8025A924 AC6406D4 */  sw        $a0, 0x6d4($v1)
/* 189208 8025A928 24840020 */  addiu     $a0, $a0, 0x20
/* 18920C 8025A92C 820206CD */  lb        $v0, 0x6cd($s0)
/* 189210 8025A930 24E70001 */  addiu     $a3, $a3, 1
/* 189214 8025A934 00E2102A */  slt       $v0, $a3, $v0
/* 189218 8025A938 1440FFFA */  bnez      $v0, .L8025A924
/* 18921C 8025A93C 24630004 */   addiu    $v1, $v1, 4
.L8025A940:
/* 189220 8025A940 820306C2 */  lb        $v1, 0x6c2($s0)
/* 189224 8025A944 28620002 */  slti      $v0, $v1, 2
/* 189228 8025A948 10400044 */  beqz      $v0, .L8025AA5C
/* 18922C 8025A94C 00000000 */   nop
/* 189230 8025A950 04600042 */  bltz      $v1, .L8025AA5C
/* 189234 8025A954 00000000 */   nop
/* 189238 8025A958 860206C8 */  lh        $v0, 0x6c8($s0)
/* 18923C 8025A95C 1C400010 */  bgtz      $v0, .L8025A9A0
/* 189240 8025A960 240300FF */   addiu    $v1, $zero, 0xff
/* 189244 8025A964 04420001 */  bltzl     $v0, .L8025A96C
/* 189248 8025A968 00021023 */   negu     $v0, $v0
.L8025A96C:
/* 18924C 8025A96C 00021040 */  sll       $v0, $v0, 1
/* 189250 8025A970 3C018028 */  lui       $at, %hi(D_802840DC)
/* 189254 8025A974 00220821 */  addu      $at, $at, $v0
/* 189258 8025A978 942240DC */  lhu       $v0, %lo(D_802840DC)($at)
/* 18925C 8025A97C A622006A */  sh        $v0, 0x6a($s1)
/* 189260 8025A980 00021400 */  sll       $v0, $v0, 0x10
/* 189264 8025A984 00021403 */  sra       $v0, $v0, 0x10
/* 189268 8025A988 14430005 */  bne       $v0, $v1, .L8025A9A0
/* 18926C 8025A98C 2404003C */   addiu    $a0, $zero, 0x3c
/* 189270 8025A990 0C00A67F */  jal       rand_int
/* 189274 8025A994 A620006A */   sh       $zero, 0x6a($s1)
/* 189278 8025A998 2442001E */  addiu     $v0, $v0, 0x1e
/* 18927C 8025A99C A60206C8 */  sh        $v0, 0x6c8($s0)
.L8025A9A0:
/* 189280 8025A9A0 16A00004 */  bnez      $s5, .L8025A9B4
/* 189284 8025A9A4 00000000 */   nop
/* 189288 8025A9A8 960206C8 */  lhu       $v0, 0x6c8($s0)
/* 18928C 8025A9AC 2442FFFF */  addiu     $v0, $v0, -1
/* 189290 8025A9B0 A60206C8 */  sh        $v0, 0x6c8($s0)
.L8025A9B4:
/* 189294 8025A9B4 860306CA */  lh        $v1, 0x6ca($s0)
/* 189298 8025A9B8 2402000C */  addiu     $v0, $zero, 0xc
/* 18929C 8025A9BC 1062000C */  beq       $v1, $v0, .L8025A9F0
/* 1892A0 8025A9C0 2862000D */   slti     $v0, $v1, 0xd
/* 1892A4 8025A9C4 10400005 */  beqz      $v0, .L8025A9DC
/* 1892A8 8025A9C8 2402000A */   addiu    $v0, $zero, 0xa
/* 1892AC 8025A9CC 10620008 */  beq       $v1, $v0, .L8025A9F0
/* 1892B0 8025A9D0 00000000 */   nop
/* 1892B4 8025A9D4 08096A88 */  j         .L8025AA20
/* 1892B8 8025A9D8 00000000 */   nop
.L8025A9DC:
/* 1892BC 8025A9DC 2402000D */  addiu     $v0, $zero, 0xd
/* 1892C0 8025A9E0 5062000F */  beql      $v1, $v0, .L8025AA20
/* 1892C4 8025A9E4 A60006CA */   sh       $zero, 0x6ca($s0)
/* 1892C8 8025A9E8 08096A88 */  j         .L8025AA20
/* 1892CC 8025A9EC 00000000 */   nop
.L8025A9F0:
/* 1892D0 8025A9F0 16800006 */  bnez      $s4, .L8025AA0C
/* 1892D4 8025A9F4 0220202D */   daddu    $a0, $s1, $zero
/* 1892D8 8025A9F8 0240282D */  daddu     $a1, $s2, $zero
/* 1892DC 8025A9FC 0C096657 */  jal       func_8025995C
/* 1892E0 8025AA00 0260302D */   daddu    $a2, $s3, $zero
/* 1892E4 8025AA04 08096A92 */  j         .L8025AA48
/* 1892E8 8025AA08 00000000 */   nop
.L8025AA0C:
/* 1892EC 8025AA0C 0240282D */  daddu     $a1, $s2, $zero
/* 1892F0 8025AA10 0C0965B0 */  jal       func_802596C0
/* 1892F4 8025AA14 0260302D */   daddu    $a2, $s3, $zero
/* 1892F8 8025AA18 08096A92 */  j         .L8025AA48
/* 1892FC 8025AA1C 00000000 */   nop
.L8025AA20:
/* 189300 8025AA20 16800006 */  bnez      $s4, .L8025AA3C
/* 189304 8025AA24 0220202D */   daddu    $a0, $s1, $zero
/* 189308 8025AA28 0240282D */  daddu     $a1, $s2, $zero
/* 18930C 8025AA2C 0C0965EC */  jal       func_802597B0
/* 189310 8025AA30 0260302D */   daddu    $a2, $s3, $zero
/* 189314 8025AA34 08096A92 */  j         .L8025AA48
/* 189318 8025AA38 00000000 */   nop
.L8025AA3C:
/* 18931C 8025AA3C 0240282D */  daddu     $a1, $s2, $zero
/* 189320 8025AA40 0C096543 */  jal       func_8025950C
/* 189324 8025AA44 0260302D */   daddu    $a2, $s3, $zero
.L8025AA48:
/* 189328 8025AA48 16A00004 */  bnez      $s5, .L8025AA5C
/* 18932C 8025AA4C 00000000 */   nop
/* 189330 8025AA50 960206CA */  lhu       $v0, 0x6ca($s0)
/* 189334 8025AA54 24420001 */  addiu     $v0, $v0, 1
/* 189338 8025AA58 A60206CA */  sh        $v0, 0x6ca($s0)
.L8025AA5C:
/* 18933C 8025AA5C 8FBF0028 */  lw        $ra, 0x28($sp)
/* 189340 8025AA60 8FB50024 */  lw        $s5, 0x24($sp)
/* 189344 8025AA64 8FB40020 */  lw        $s4, 0x20($sp)
/* 189348 8025AA68 8FB3001C */  lw        $s3, 0x1c($sp)
/* 18934C 8025AA6C 8FB20018 */  lw        $s2, 0x18($sp)
/* 189350 8025AA70 8FB10014 */  lw        $s1, 0x14($sp)
/* 189354 8025AA74 8FB00010 */  lw        $s0, 0x10($sp)
/* 189358 8025AA78 03E00008 */  jr        $ra
/* 18935C 8025AA7C 27BD0030 */   addiu    $sp, $sp, 0x30
