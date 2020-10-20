.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240870_DB8180
/* DB8180 80240870 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DB8184 80240874 AFB00010 */  sw        $s0, 0x10($sp)
/* DB8188 80240878 3C108024 */  lui       $s0, 0x8024
/* DB818C 8024087C 261056C0 */  addiu     $s0, $s0, 0x56c0
/* DB8190 80240880 AFBF0018 */  sw        $ra, 0x18($sp)
/* DB8194 80240884 AFB10014 */  sw        $s1, 0x14($sp)
/* DB8198 80240888 8E020000 */  lw        $v0, ($s0)
/* DB819C 8024088C 14400010 */  bnez      $v0, .L802408D0
/* DB81A0 80240890 0080882D */   daddu    $s1, $a0, $zero
/* DB81A4 80240894 0C00AB39 */  jal       heap_malloc
/* DB81A8 80240898 24040040 */   addiu    $a0, $zero, 0x40
/* DB81AC 8024089C AE020000 */  sw        $v0, ($s0)
/* DB81B0 802408A0 0000182D */  daddu     $v1, $zero, $zero
/* DB81B4 802408A4 0040282D */  daddu     $a1, $v0, $zero
/* DB81B8 802408A8 0220202D */  daddu     $a0, $s1, $zero
.L802408AC:
/* DB81BC 802408AC 8C820084 */  lw        $v0, 0x84($a0)
/* DB81C0 802408B0 24840004 */  addiu     $a0, $a0, 4
/* DB81C4 802408B4 24630001 */  addiu     $v1, $v1, 1
/* DB81C8 802408B8 ACA20000 */  sw        $v0, ($a1)
/* DB81CC 802408BC 28620010 */  slti      $v0, $v1, 0x10
/* DB81D0 802408C0 1440FFFA */  bnez      $v0, .L802408AC
/* DB81D4 802408C4 24A50004 */   addiu    $a1, $a1, 4
/* DB81D8 802408C8 08090243 */  j         .L8024090C
/* DB81DC 802408CC 00000000 */   nop      
.L802408D0:
/* DB81E0 802408D0 0000182D */  daddu     $v1, $zero, $zero
/* DB81E4 802408D4 0040282D */  daddu     $a1, $v0, $zero
/* DB81E8 802408D8 0220202D */  daddu     $a0, $s1, $zero
.L802408DC:
/* DB81EC 802408DC 8CA20000 */  lw        $v0, ($a1)
/* DB81F0 802408E0 24A50004 */  addiu     $a1, $a1, 4
/* DB81F4 802408E4 24630001 */  addiu     $v1, $v1, 1
/* DB81F8 802408E8 AC820084 */  sw        $v0, 0x84($a0)
/* DB81FC 802408EC 28620010 */  slti      $v0, $v1, 0x10
/* DB8200 802408F0 1440FFFA */  bnez      $v0, .L802408DC
/* DB8204 802408F4 24840004 */   addiu    $a0, $a0, 4
/* DB8208 802408F8 3C108024 */  lui       $s0, 0x8024
/* DB820C 802408FC 261056C0 */  addiu     $s0, $s0, 0x56c0
/* DB8210 80240900 0C00AB4B */  jal       heap_free
/* DB8214 80240904 8E040000 */   lw       $a0, ($s0)
/* DB8218 80240908 AE000000 */  sw        $zero, ($s0)
.L8024090C:
/* DB821C 8024090C 8FBF0018 */  lw        $ra, 0x18($sp)
/* DB8220 80240910 8FB10014 */  lw        $s1, 0x14($sp)
/* DB8224 80240914 8FB00010 */  lw        $s0, 0x10($sp)
/* DB8228 80240918 24020002 */  addiu     $v0, $zero, 2
/* DB822C 8024091C 03E00008 */  jr        $ra
/* DB8230 80240920 27BD0020 */   addiu    $sp, $sp, 0x20
