.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B704C
/* E218BC 802B704C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E218C0 802B7050 AFB00010 */  sw        $s0, 0x10($sp)
/* E218C4 802B7054 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* E218C8 802B7058 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* E218CC 802B705C AFBF0014 */  sw        $ra, 0x14($sp)
/* E218D0 802B7060 0C011052 */  jal       func_80044148
/* E218D4 802B7064 00000000 */   nop
/* E218D8 802B7068 14400031 */  bnez      $v0, .L802B7130
/* E218DC 802B706C 0000102D */   daddu    $v0, $zero, $zero
/* E218E0 802B7070 8E020000 */  lw        $v0, ($s0)
/* E218E4 802B7074 30420020 */  andi      $v0, $v0, 0x20
/* E218E8 802B7078 1440002D */  bnez      $v0, .L802B7130
/* E218EC 802B707C 0000102D */   daddu    $v0, $zero, $zero
/* E218F0 802B7080 8E020004 */  lw        $v0, 4($s0)
/* E218F4 802B7084 30420080 */  andi      $v0, $v0, 0x80
/* E218F8 802B7088 10400029 */  beqz      $v0, .L802B7130
/* E218FC 802B708C 0000102D */   daddu    $v0, $zero, $zero
/* E21900 802B7090 0C03814E */  jal       func_800E0538
/* E21904 802B7094 00000000 */   nop
/* E21908 802B7098 14400025 */  bnez      $v0, .L802B7130
/* E2190C 802B709C 0000102D */   daddu    $v0, $zero, $zero
/* E21910 802B70A0 0C0381B6 */  jal       func_800E06D8
/* E21914 802B70A4 00000000 */   nop
/* E21918 802B70A8 14400021 */  bnez      $v0, .L802B7130
/* E2191C 802B70AC 0000102D */   daddu    $v0, $zero, $zero
/* E21920 802B70B0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* E21924 802B70B4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* E21928 802B70B8 3C049249 */  lui       $a0, 0x9249
/* E2192C 802B70BC 9443008C */  lhu       $v1, 0x8c($v0)
/* E21930 802B70C0 34842493 */  ori       $a0, $a0, 0x2493
/* E21934 802B70C4 00031C00 */  sll       $v1, $v1, 0x10
/* E21938 802B70C8 00031403 */  sra       $v0, $v1, 0x10
/* E2193C 802B70CC 00440018 */  mult      $v0, $a0
/* E21940 802B70D0 00031FC3 */  sra       $v1, $v1, 0x1f
/* E21944 802B70D4 00002810 */  mfhi      $a1
/* E21948 802B70D8 00A22021 */  addu      $a0, $a1, $v0
/* E2194C 802B70DC 00042083 */  sra       $a0, $a0, 2
/* E21950 802B70E0 00832023 */  subu      $a0, $a0, $v1
/* E21954 802B70E4 000418C0 */  sll       $v1, $a0, 3
/* E21958 802B70E8 00641823 */  subu      $v1, $v1, $a0
/* E2195C 802B70EC 00431023 */  subu      $v0, $v0, $v1
/* E21960 802B70F0 00021400 */  sll       $v0, $v0, 0x10
/* E21964 802B70F4 00021403 */  sra       $v0, $v0, 0x10
/* E21968 802B70F8 2442FFFE */  addiu     $v0, $v0, -2
/* E2196C 802B70FC 04420001 */  bltzl     $v0, .L802B7104
/* E21970 802B7100 00021023 */   negu     $v0, $v0
.L802B7104:
/* E21974 802B7104 00042400 */  sll       $a0, $a0, 0x10
/* E21978 802B7108 00042403 */  sra       $a0, $a0, 0x10
/* E2197C 802B710C 00441021 */  addu      $v0, $v0, $a0
/* E21980 802B7110 28420006 */  slti      $v0, $v0, 6
/* E21984 802B7114 10400006 */  beqz      $v0, .L802B7130
/* E21988 802B7118 0000102D */   daddu    $v0, $zero, $zero
/* E2198C 802B711C 0C0ADC00 */  jal       func_802B7000_2
/* E21990 802B7120 00000000 */   nop
/* E21994 802B7124 14400002 */  bnez      $v0, .L802B7130
/* E21998 802B7128 0000102D */   daddu    $v0, $zero, $zero
/* E2199C 802B712C 24020001 */  addiu     $v0, $zero, 1
.L802B7130:
/* E219A0 802B7130 8FBF0014 */  lw        $ra, 0x14($sp)
/* E219A4 802B7134 8FB00010 */  lw        $s0, 0x10($sp)
/* E219A8 802B7138 03E00008 */  jr        $ra
/* E219AC 802B713C 27BD0018 */   addiu    $sp, $sp, 0x18
