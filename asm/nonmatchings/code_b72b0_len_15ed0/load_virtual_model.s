.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel load_virtual_model
/* B73E0 80120CE0 3C038015 */  lui       $v1, 0x8015
/* B73E4 80120CE4 8C634370 */  lw        $v1, 0x4370($v1)
/* B73E8 80120CE8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B73EC 80120CEC AFB10014 */  sw        $s1, 0x14($sp)
/* B73F0 80120CF0 0080882D */  daddu     $s1, $a0, $zero
/* B73F4 80120CF4 AFB00010 */  sw        $s0, 0x10($sp)
/* B73F8 80120CF8 0000802D */  daddu     $s0, $zero, $zero
/* B73FC 80120CFC AFBF0018 */  sw        $ra, 0x18($sp)
.L80120D00:
/* B7400 80120D00 8C620000 */  lw        $v0, ($v1)
/* B7404 80120D04 10400006 */  beqz      $v0, .L80120D20
/* B7408 80120D08 2A020100 */   slti     $v0, $s0, 0x100
/* B740C 80120D0C 26100001 */  addiu     $s0, $s0, 1
/* B7410 80120D10 2A020100 */  slti      $v0, $s0, 0x100
/* B7414 80120D14 1440FFFA */  bnez      $v0, .L80120D00
/* B7418 80120D18 24630004 */   addiu    $v1, $v1, 4
/* B741C 80120D1C 2A020100 */  slti      $v0, $s0, 0x100
.L80120D20:
/* B7420 80120D20 14400003 */  bnez      $v0, .L80120D30
/* B7424 80120D24 00000000 */   nop      
.L80120D28:
/* B7428 80120D28 0804834A */  j         .L80120D28
/* B742C 80120D2C 00000000 */   nop      
.L80120D30:
/* B7430 80120D30 0C00AB39 */  jal       heap_malloc
/* B7434 80120D34 24040068 */   addiu    $a0, $zero, 0x68
/* B7438 80120D38 00102080 */  sll       $a0, $s0, 2
/* B743C 80120D3C 3C038015 */  lui       $v1, 0x8015
/* B7440 80120D40 8C634370 */  lw        $v1, 0x4370($v1)
/* B7444 80120D44 3C058015 */  lui       $a1, 0x8015
/* B7448 80120D48 24A51318 */  addiu     $a1, $a1, 0x1318
/* B744C 80120D4C 00832021 */  addu      $a0, $a0, $v1
/* B7450 80120D50 8CA30000 */  lw        $v1, ($a1)
/* B7454 80120D54 0040302D */  daddu     $a2, $v0, $zero
/* B7458 80120D58 AC860000 */  sw        $a2, ($a0)
/* B745C 80120D5C 24630001 */  addiu     $v1, $v1, 1
/* B7460 80120D60 14C00003 */  bnez      $a2, .L80120D70
/* B7464 80120D64 ACA30000 */   sw       $v1, ($a1)
.L80120D68:
/* B7468 80120D68 0804835A */  j         .L80120D68
/* B746C 80120D6C 00000000 */   nop      
.L80120D70:
/* B7470 80120D70 3C013F80 */  lui       $at, 0x3f80
/* B7474 80120D74 44810000 */  mtc1      $at, $f0
/* B7478 80120D78 24020017 */  addiu     $v0, $zero, 0x17
/* B747C 80120D7C ACC20000 */  sw        $v0, ($a2)
/* B7480 80120D80 24020001 */  addiu     $v0, $zero, 1
/* B7484 80120D84 A0C20004 */  sb        $v0, 4($a2)
/* B7488 80120D88 ACC00014 */  sw        $zero, 0x14($a2)
/* B748C 80120D8C ACD10010 */  sw        $s1, 0x10($a2)
/* B7490 80120D90 E4C00008 */  swc1      $f0, 8($a2)
/* B7494 80120D94 16200004 */  bnez      $s1, .L80120DA8
/* B7498 80120D98 E4C0000C */   swc1     $f0, 0xc($a2)
/* B749C 80120D9C 3C028015 */  lui       $v0, 0x8015
/* B74A0 80120DA0 2442C260 */  addiu     $v0, $v0, -0x3da0
/* B74A4 80120DA4 ACC20010 */  sw        $v0, 0x10($a2)
.L80120DA8:
/* B74A8 80120DA8 8CC20010 */  lw        $v0, 0x10($a2)
/* B74AC 80120DAC 3C038007 */  lui       $v1, 0x8007
/* B74B0 80120DB0 8C63419C */  lw        $v1, 0x419c($v1)
/* B74B4 80120DB4 ACC0005C */  sw        $zero, 0x5c($a2)
/* B74B8 80120DB8 ACC00060 */  sw        $zero, 0x60($a2)
/* B74BC 80120DBC ACC20058 */  sw        $v0, 0x58($a2)
/* B74C0 80120DC0 80620070 */  lb        $v0, 0x70($v1)
/* B74C4 80120DC4 54400001 */  bnel      $v0, $zero, .L80120DCC
/* B74C8 80120DC8 36100800 */   ori      $s0, $s0, 0x800
.L80120DCC:
/* B74CC 80120DCC 0200102D */  daddu     $v0, $s0, $zero
/* B74D0 80120DD0 8FBF0018 */  lw        $ra, 0x18($sp)
/* B74D4 80120DD4 8FB10014 */  lw        $s1, 0x14($sp)
/* B74D8 80120DD8 8FB00010 */  lw        $s0, 0x10($sp)
/* B74DC 80120DDC 03E00008 */  jr        $ra
/* B74E0 80120DE0 27BD0020 */   addiu    $sp, $sp, 0x20
