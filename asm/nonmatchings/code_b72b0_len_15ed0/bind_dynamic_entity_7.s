.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel bind_dynamic_entity_7
/* B993C 8012323C 3C038015 */  lui       $v1, %hi(gCurrentDynamicEntityListPtr)
/* B9940 80123240 8C634420 */  lw        $v1, %lo(gCurrentDynamicEntityListPtr)($v1)
/* B9944 80123244 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B9948 80123248 AFB10014 */  sw        $s1, 0x14($sp)
/* B994C 8012324C 0080882D */  daddu     $s1, $a0, $zero
/* B9950 80123250 AFB20018 */  sw        $s2, 0x18($sp)
/* B9954 80123254 00A0902D */  daddu     $s2, $a1, $zero
/* B9958 80123258 AFB00010 */  sw        $s0, 0x10($sp)
/* B995C 8012325C 0000802D */  daddu     $s0, $zero, $zero
/* B9960 80123260 AFBF001C */  sw        $ra, 0x1c($sp)
.L80123264:
/* B9964 80123264 8C620000 */  lw        $v0, ($v1)
/* B9968 80123268 10400006 */  beqz      $v0, .L80123284
/* B996C 8012326C 2A020010 */   slti     $v0, $s0, 0x10
/* B9970 80123270 26100001 */  addiu     $s0, $s0, 1
/* B9974 80123274 2A020010 */  slti      $v0, $s0, 0x10
/* B9978 80123278 1440FFFA */  bnez      $v0, .L80123264
/* B997C 8012327C 24630004 */   addiu    $v1, $v1, 4
/* B9980 80123280 2A020010 */  slti      $v0, $s0, 0x10
.L80123284:
/* B9984 80123284 14400003 */  bnez      $v0, .L80123294
/* B9988 80123288 00000000 */   nop      
.L8012328C:
/* B998C 8012328C 08048CA3 */  j         .L8012328C
/* B9990 80123290 00000000 */   nop      
.L80123294:
/* B9994 80123294 0C00AB39 */  jal       heap_malloc
/* B9998 80123298 2404000C */   addiu    $a0, $zero, 0xc
/* B999C 8012329C 3C048015 */  lui       $a0, %hi(gCurrentDynamicEntityListPtr)
/* B99A0 801232A0 8C844420 */  lw        $a0, %lo(gCurrentDynamicEntityListPtr)($a0)
/* B99A4 801232A4 00101880 */  sll       $v1, $s0, 2
/* B99A8 801232A8 00641821 */  addu      $v1, $v1, $a0
/* B99AC 801232AC 0040202D */  daddu     $a0, $v0, $zero
/* B99B0 801232B0 14800003 */  bnez      $a0, .L801232C0
/* B99B4 801232B4 AC640000 */   sw       $a0, ($v1)
.L801232B8:
/* B99B8 801232B8 08048CAE */  j         .L801232B8
/* B99BC 801232BC 00000000 */   nop      
.L801232C0:
/* B99C0 801232C0 24020007 */  addiu     $v0, $zero, 7
/* B99C4 801232C4 AC820000 */  sw        $v0, ($a0)
/* B99C8 801232C8 16200004 */  bnez      $s1, .L801232DC
/* B99CC 801232CC AC910004 */   sw       $s1, 4($a0)
/* B99D0 801232D0 3C028012 */  lui       $v0, 0x8012
/* B99D4 801232D4 244230B0 */  addiu     $v0, $v0, 0x30b0
/* B99D8 801232D8 AC820004 */  sw        $v0, 4($a0)
.L801232DC:
/* B99DC 801232DC 16400004 */  bnez      $s2, .L801232F0
/* B99E0 801232E0 AC920008 */   sw       $s2, 8($a0)
/* B99E4 801232E4 3C028012 */  lui       $v0, 0x8012
/* B99E8 801232E8 244230B0 */  addiu     $v0, $v0, 0x30b0
/* B99EC 801232EC AC820008 */  sw        $v0, 8($a0)
.L801232F0:
/* B99F0 801232F0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* B99F4 801232F4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* B99F8 801232F8 80420070 */  lb        $v0, 0x70($v0)
/* B99FC 801232FC 54400001 */  bnel      $v0, $zero, .L80123304
/* B9A00 80123300 36100800 */   ori      $s0, $s0, 0x800
.L80123304:
/* B9A04 80123304 0200102D */  daddu     $v0, $s0, $zero
/* B9A08 80123308 8FBF001C */  lw        $ra, 0x1c($sp)
/* B9A0C 8012330C 8FB20018 */  lw        $s2, 0x18($sp)
/* B9A10 80123310 8FB10014 */  lw        $s1, 0x14($sp)
/* B9A14 80123314 8FB00010 */  lw        $s0, 0x10($sp)
/* B9A18 80123318 03E00008 */  jr        $ra
/* B9A1C 8012331C 27BD0020 */   addiu    $sp, $sp, 0x20
