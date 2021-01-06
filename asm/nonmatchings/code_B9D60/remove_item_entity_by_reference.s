.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel remove_item_entity_by_reference
/* CA030 80133930 3C038015 */  lui       $v1, %hi(D_801565A0)
/* CA034 80133934 8C6365A0 */  lw        $v1, %lo(D_801565A0)($v1)
/* CA038 80133938 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CA03C 8013393C AFB10014 */  sw        $s1, 0x14($sp)
/* CA040 80133940 0080882D */  daddu     $s1, $a0, $zero
/* CA044 80133944 AFB00010 */  sw        $s0, 0x10($sp)
/* CA048 80133948 0000802D */  daddu     $s0, $zero, $zero
/* CA04C 8013394C AFBF0018 */  sw        $ra, 0x18($sp)
.L80133950:
/* CA050 80133950 8C620000 */  lw        $v0, ($v1)
/* CA054 80133954 10510006 */  beq       $v0, $s1, .L80133970
/* CA058 80133958 2A020100 */   slti     $v0, $s0, 0x100
/* CA05C 8013395C 26100001 */  addiu     $s0, $s0, 1
/* CA060 80133960 2A020100 */  slti      $v0, $s0, 0x100
/* CA064 80133964 1440FFFA */  bnez      $v0, .L80133950
/* CA068 80133968 24630004 */   addiu    $v1, $v1, 4
/* CA06C 8013396C 2A020100 */  slti      $v0, $s0, 0x100
.L80133970:
/* CA070 80133970 1040001D */  beqz      $v0, .L801339E8
/* CA074 80133974 00000000 */   nop      
/* CA078 80133978 8E240014 */  lw        $a0, 0x14($s1)
/* CA07C 8013397C 10800003 */  beqz      $a0, .L8013398C
/* CA080 80133980 00000000 */   nop      
/* CA084 80133984 0C00AB4B */  jal       heap_free
/* CA088 80133988 00000000 */   nop      
.L8013398C:
/* CA08C 8013398C 8223001B */  lb        $v1, 0x1b($s1)
/* CA090 80133990 2C62001D */  sltiu     $v0, $v1, 0x1d
/* CA094 80133994 10400008 */  beqz      $v0, .L801339B8
/* CA098 80133998 00031080 */   sll      $v0, $v1, 2
/* CA09C 8013399C 3C018015 */  lui       $at, %hi(D_80150D28)
/* CA0A0 801339A0 00220821 */  addu      $at, $at, $v0
/* CA0A4 801339A4 8C220D28 */  lw        $v0, %lo(D_80150D28)($at)
/* CA0A8 801339A8 00400008 */  jr        $v0
/* CA0AC 801339AC 00000000 */   nop      
/* CA0B0 801339B0 0C0448CA */  jal       func_80112328
/* CA0B4 801339B4 86240020 */   lh       $a0, 0x20($s1)
.L801339B8:
/* CA0B8 801339B8 3C118015 */  lui       $s1, %hi(D_801565A0)
/* CA0BC 801339BC 263165A0 */  addiu     $s1, $s1, %lo(D_801565A0)
/* CA0C0 801339C0 8E220000 */  lw        $v0, ($s1)
/* CA0C4 801339C4 00108080 */  sll       $s0, $s0, 2
/* CA0C8 801339C8 02021021 */  addu      $v0, $s0, $v0
/* CA0CC 801339CC 0C00AB4B */  jal       heap_free
/* CA0D0 801339D0 8C440000 */   lw       $a0, ($v0)
/* CA0D4 801339D4 8E220000 */  lw        $v0, ($s1)
/* CA0D8 801339D8 3C018015 */  lui       $at, %hi(D_801565A4)
/* CA0DC 801339DC A42065A4 */  sh        $zero, %lo(D_801565A4)($at)
/* CA0E0 801339E0 02028021 */  addu      $s0, $s0, $v0
/* CA0E4 801339E4 AE000000 */  sw        $zero, ($s0)
.L801339E8:
/* CA0E8 801339E8 8FBF0018 */  lw        $ra, 0x18($sp)
/* CA0EC 801339EC 8FB10014 */  lw        $s1, 0x14($sp)
/* CA0F0 801339F0 8FB00010 */  lw        $s0, 0x10($sp)
/* CA0F4 801339F4 03E00008 */  jr        $ra
/* CA0F8 801339F8 27BD0020 */   addiu    $sp, $sp, 0x20
