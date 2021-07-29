.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel create_status_icon_boost_jump
/* 23014 80047C14 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 23018 80047C18 00041040 */  sll       $v0, $a0, 1
/* 2301C 80047C1C 00441021 */  addu      $v0, $v0, $a0
/* 23020 80047C20 00021080 */  sll       $v0, $v0, 2
/* 23024 80047C24 00441023 */  subu      $v0, $v0, $a0
/* 23028 80047C28 3C03800A */  lui       $v1, %hi(D_800A0F44)
/* 2302C 80047C2C 8C630F44 */  lw        $v1, %lo(D_800A0F44)($v1)
/* 23030 80047C30 00021100 */  sll       $v0, $v0, 4
/* 23034 80047C34 AFBF0018 */  sw        $ra, 0x18($sp)
/* 23038 80047C38 AFB10014 */  sw        $s1, 0x14($sp)
/* 2303C 80047C3C AFB00010 */  sw        $s0, 0x10($sp)
/* 23040 80047C40 00628821 */  addu      $s1, $v1, $v0
/* 23044 80047C44 2403FFBF */  addiu     $v1, $zero, -0x41
/* 23048 80047C48 8E220000 */  lw        $v0, ($s1)
/* 2304C 80047C4C 82240078 */  lb        $a0, 0x78($s1)
/* 23050 80047C50 00431024 */  and       $v0, $v0, $v1
/* 23054 80047C54 1480000E */  bnez      $a0, .L80047C90
/* 23058 80047C58 AE220000 */   sw       $v0, ($s1)
/* 2305C 80047C5C 3C048010 */  lui       $a0, %hi(D_8010701C)
/* 23060 80047C60 2484701C */  addiu     $a0, $a0, %lo(D_8010701C)
/* 23064 80047C64 24020001 */  addiu     $v0, $zero, 1
/* 23068 80047C68 0C050529 */  jal       create_hud_element
/* 2306C 80047C6C A2220078 */   sb       $v0, 0x78($s1)
/* 23070 80047C70 0040802D */  daddu     $s0, $v0, $zero
/* 23074 80047C74 0200202D */  daddu     $a0, $s0, $zero
/* 23078 80047C78 0C051280 */  jal       set_hud_element_flags
/* 2307C 80047C7C 24050002 */   addiu    $a1, $zero, 2
/* 23080 80047C80 0200202D */  daddu     $a0, $s0, $zero
/* 23084 80047C84 0C051280 */  jal       set_hud_element_flags
/* 23088 80047C88 24050080 */   addiu    $a1, $zero, 0x80
/* 2308C 80047C8C AE30007C */  sw        $s0, 0x7c($s1)
.L80047C90:
/* 23090 80047C90 8FBF0018 */  lw        $ra, 0x18($sp)
/* 23094 80047C94 8FB10014 */  lw        $s1, 0x14($sp)
/* 23098 80047C98 8FB00010 */  lw        $s0, 0x10($sp)
/* 2309C 80047C9C 03E00008 */  jr        $ra
/* 230A0 80047CA0 27BD0020 */   addiu    $sp, $sp, 0x20
